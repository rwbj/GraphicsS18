/*file:sceneViewer.h
 *author:ryan cosgrove(ryancosgrove@gmail.com*/
#include <stdlib.h>
#include <unistd.h>
#include <lvr.h>

/*shared memory segment*/
int 		shmid;
struct sseg*	shmseg;

/*timing + frames*/
uint32_t	thisTime=0;
uint32_t	lastTime=0;
uint32_t	frame=0;
uint32_t	lastFrame=0;
uint32_t	lastFC=0;
float 		iod = 0.016f;		//interocular distance; 1.0u == 4m;  0.016 == 64mm == what the army claims is mean; stdv is 3.somethingmm
float 		moveSpeed = 0.000001f; //in m/s
unsigned int 	shutdownCount=0;

//init shm
//---------------------------------------------------------------------------//
int initshm(struct sseg** s) 
{
	int shm_id;
	printf("creating/finding shared memory segment\n");
	if ( (shm_id = shmget(27, sizeof(struct sseg), IPC_CREAT |  0666)) == -1) {
		printf("shmget failed, errno = %d   %s\n", errno, strerror(errno));
		exit(1);
	}

	if   ( (*s= (struct sseg *) shmat(shm_id, 0, 0)) == (void *) -1) {
		printf("shmat failed, errno = %d   %s\n", errno, strerror(errno));
		exit(1);
	}
	printf("shared memory created/found and attached on page boundary\n");
	return shm_id;
}

///Initialization - load scene, initialize scene, SDL, GL, and user input
//---------------------------------------------------------------------------//
bool init(int argc, char** argv)
{
	int 		i = 0;
	uint32_t 	options = 0, startTime = 0, endTime = 0;
	bool 		bad_arg = false;

	/*parse arguments*/
	for(i=1; i<argc-1 && !bad_arg;i++)
	{	
		if(argv[i][0] == '-')
		{
			switch( argv[i][1] )
			{

				case '-':
					if(strncmp(argv[i],"--no-materials",16)==0)
					{
						zlogd("debug:no materials!");
						options |= HAS_COLORS;		
					}
					else
						if(strncmp(argv[i],"--no-lighting",16)==0)
						{
							zlogd("debug:no lighting!");
							options |= HAS_NORMALS;
						}
						else
							if(strncmp(argv[i],"--no-textures",16)==0)
							{
								zlogd("debug:no textures!");
								options |= HAS_UV_COORDS;
							}
							else
							{
								if(strncmp(argv[i],"--use-basic-input",16)==0)
									basicInput = true;
								else
									bad_arg = true;
							}
					break;

				default:
					bad_arg = true;
					break;
			}
		}
	}

	/*exit if encountered a bad argument*/
	if(bad_arg)
	{
		zloge("\nusage: %s [OPTIONS]... FILE",argv[0]);
		zloge("\nOPTIONS");
		zloge("\t--use-basic-input\n\t\tenable keyboard-mouse input\n\t--no-materials\n\t\tdisables materials\n\t--no-lighting\n\t\tdisables lighting\n\t--no-textures\n\t\tdisables textures");
		exit(0);
	}

	///Initialize functions	
	shmid = initshm(&shmseg);

	///initialize opengl and sdl
	if( !initSDLGL("LVR Engine", 1080,1920, 3, 3) )
	{ zlogi("info: could not initialize sdl/opengl"); return false;}	


		startTime=SDL_GetTicks();
	///load the scene with assimp and fill our datastructure
	if( ( scene = loadScene(argv[argc-1], options)) == NULL )
	{ zlogi("info: could not initialize scene"); return false;}
		endTime=SDL_GetTicks();
		zlogd("scene took %f seconds to load",(endTime-startTime)/1000.0f);


		startTime=SDL_GetTicks();
	///initialize the scene (data transfer to GPU, etc)
	if( !initScene(scene) )
	{ zlogi("info: could not format scene properly"); return false;}
		endTime=SDL_GetTicks();
		zlogd("scene took %f seconds to initialize",(endTime-startTime)/1000.0f);


	///initialize user input 
	if( !initUserInput() )
	{ zlogi("init: could not initialize user input"); return false;}

	///initialized successfully!
	return true;
}

///program entry - 
//---------------------------------------------------------------------------//
int main(int argc,char** argv)
{
	char* dbgcont = getenv("DBGSTR");
	if(dbgcont!=NULL)
		if(strchr(dbgcont,'e')==NULL)
		{
			ZL_DisableLogging(ZL_INFO);
		}
	/*enable logging*/	
	ZL_EnableLogging(ZL_DEBUG);
	ZL_EnableLogging(ZL_VERBOSE);
	ZL_EnableLogging(ZL_INFO);

	if( init(argc,argv) )
	{
		zlogi("info: initialization complete");

		/*set up projection matrix*/
		if(basicInput)
		{
			proj_matrix = glm::perspective( 45.0, 960.0/1080.0, 0.1, 1000.0 );
			//proj_matrix = glm::perspective( 45.0, 1080.0/960.0, 0.1, 1000.0 );
		}
		else
		{
			/*set up perspective view frustrum*/
			proj_matrix = glm::perspective( 45.0, 1080.0/960.0, 0.1, 1000.0 );
			
			/*set up camera looking down -Z axis*/

			lview_matrix = glm::lookAt( glm::vec3(	   0.0, 0.0, -iod/2.0),
			/*left eye*/		    glm::vec3(     10.0, 0.0, 0.0),
					            glm::vec3(     0.0, 1.0, 0.0));
			
			rview_matrix = glm::lookAt( glm::vec3( 	   0.0, 0.0, iod/2.0),
			/*right eye*/		    glm::vec3(     10.0, 0.0, 0.0),
						    glm::vec3(     0.0, 1.0, 0.0));
			
			/*rotate view matrices about the z-axis*/
			rview_matrix = glm::rotate(rview_matrix, -90.0f*0.0175f, glm::vec3(1,0,0));
			lview_matrix = glm::rotate(lview_matrix, -90.0f*0.0175f, glm::vec3(1,0,0));
				
		}

		run();
	}
	else
	{
		zloge("ERROR: initialization failed-exiting");
		cleanUp();
		return 0xdeadbeef;
	}
	cleanUp();
	return 0xbee51111;
}


///MAIN LOOP - run, update, draw
//---------------------------------------------------------------------------//
void run()
{
	running=true;
	while(running)
	{
		update();
		draw();
	}
}

/*update state*/
void update()
{
	float updateRate;
	glm::mat4 rotation;
	glm::mat4 translation;
	glm::mat4 scale;

	thisTime = SDL_GetTicks();///get time in ms	
	updateRate = (float)thisTime-(float)lastTime/1000.0f;
	lastTime = thisTime;

	/*update input*/
	input.mouse.ry=input.mouse.rx=0; 
	input.process();

	//how the user shuts off, or reboots, the explorer
	if ((shmseg->btn0) && (shmseg->btn1)){
		shutdownCount++;
	} else {
		//reboot
		if (shutdownCount > 1600) {
			if (shmseg->rawV < 32) {
				exit(19);
			} else {
			 exit(23);
			}
		}
		shutdownCount=0;
	}

	
	
	if(basicInput)/*KEYBOARD+MOUSE*/
	{
		yRot += -input.mouse.rx*0.0175;
		xRot += -input.mouse.ry*0.0175;
		pos += vel*(float)updateRate;
		vel*=0.9;

		lookingAt.x = pos.x + sin(yRot)*cos(xRot);
		lookingAt.y = pos.y + sin(xRot);
		lookingAt.z = pos.z + cos(yRot)*cos(xRot);
	
		view_matrix = glm::lookAt( pos, lookingAt,vec3(0.0,1.0,0.0));
	}
	else/*OCULUS + ACCEL-GYRO/PIKSI*/
	{
		if(0/*shmseg->usegps*/)	/*gps*/
		{
			pos += glm::vec3( shmseg->dx, shmseg->dy, shmseg->dz ) * moveSpeed * updateRate / worldScale;
		}
		else			/*accel*/
		{
			pos += glm::vec3( shmseg->wx, shmseg->wy, shmseg->wz ) * moveSpeed * updateRate / worldScale;
		}

		/*levitate*/
		pos.y -= shmseg->levitate * moveSpeed * updateRate / worldScale;
			
		/*scale if top button pressed*/
		if(shmseg->btn1)
		{
			worldScale += worldScale * shmseg->scale * updateRate*0.000001;
		}

		/*matrices*/
		rotation = glm::eulerAngleYXZ( shmseg->yaw, shmseg->pitch, shmseg->roll);
		translation = glm::translate(glm::mat4(1.0f),pos/worldScale);	
		scale = glm::mat4(worldScale);

		/*setup model matrix*/
		modl_matrix = rotation*translation*scale;
	}

	/*set light position if bottom button is pressed*/
	if(shmseg->btn0)
	{
		printf("#########################WORLD SCALE = %f\n", worldScale);
		printf("#########################WORLD SCALE = %f\n", worldScale);
		printf("#########################WORLD SCALE = %f\n", worldScale);
		setLightPosition();	
	}
	
	/*fps*/	
	if((thisTime-lastFC)>5000)
	{
		printf("FPS: %d - %d frames in %1.1f seconds\n", (frame-lastFrame)/5, frame-lastFrame,(thisTime-lastFC)/1000.0f);
		lastFrame = frame;
		lastFC = thisTime;
	}	
}

/*Render*/
void draw()
{
	//clear the screen
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//left eye	
	mvp_matrix = proj_matrix*lview_matrix*modl_matrix;
	
	glViewport(0,0,1080,960);
	sceneGroup->draw();

	//right eye
	mvp_matrix = proj_matrix*rview_matrix*modl_matrix;
	
	glViewport(0,960,1080,960);
	sceneGroup->draw();

	//swap window and increment frame count
	SDL_GL_SwapWindow(win);
	frame++;
}

/*clean*/
void cleanUp()
{
	int i;
	printf("cleanup\n");
	/*self explanitory*/

if(scene != NULL)
{
	if(scene->vertices!=NULL)
	{
		printf("freeing vertices... ");
		free(scene->vertices);
		printf("done\n");
	}

	if(scene->vColors!=NULL)
	{
		printf("freeing colors... ");	
		free(scene->vColors);
		printf("done\n");
	}

	if(scene->vNormals!=NULL)
	{
		printf("freeing normals... ");
		free(scene->vNormals);
		printf("done\n");
	}

	if(scene->vTexCoords!=NULL)
	{
		printf("freeing UV coordinates... ");
		free(scene->vTexCoords);
		printf("done\n");
	}

	if(scene->fIndices!=NULL)
	{
		printf("freeing indices... ");
		free(scene->fIndices);
		printf("done\n");
	}	

	if(scene->meshes!=NULL)
	{
		printf("freeing meshes... ");
		free(scene->meshes);
		printf("done\n");
	}

	if(scene->materials!=NULL)
	{
		printf("freeing materials... ");
		free(scene->materials);
		printf("done\n");
	}

	if(scene->atlas!=NULL)
	{
		printf("freeing atlas pixeldata... ");
		free(scene->atlas->pixelData);
		printf("done\n");
		
		free(scene->atlas->image);	
	}

	if(scene->textures!=NULL)
	{
		//printf("freeing %d textures... ");
		printf("freeing textures... ");
		free(scene->textures);
		printf("done\n");
	}
	
	free(scene);
}	
	printf("cleanup complete\n");
	
	if(ZLogFile)fclose(ZLogFile);

	FreeImage_DeInitialise();	
	SDL_DestroyWindow(win);
	SDL_GL_DeleteContext(context);
	SDL_Quit();
}



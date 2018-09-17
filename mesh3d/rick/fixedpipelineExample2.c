#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define VCOUNT 4

double zNear=1.0;
struct vertex nret;
struct aface {
	int v0,v1,v2;
};

int vcnt=0;
struct vertex {
	float x,y,z,c,i;
};

struct vertex *v;
struct aface *flist;
int facecnt=0;
float r=0, g=0, b=0;

float rangeX = 929.829102;
float rangeY = 533.771484;
float rangeZ = 1597.038818;
float *thetas;
//struct vertex *getNorm(struct vertex *, struct vertex *, struct vertex *);

init(argv)
char **argv;
{
	register int i;
	float minx,maxx,miny,maxy,minz,maxz;
	struct vertex *n;
	struct vertex v1,v2,norm;
	float nme;

	getModel(argv[1], &v, &vcnt, &flist, &facecnt);

printf("vcnt = %d   facecnt = %d\n", vcnt, facecnt);

	thetas = calloc(facecnt, sizeof(float));
	for (i=0; i< facecnt; i++) {
		v1.x = v[flist[i].v1].x - v[flist[i].v0].x;  v1.y = v[flist[i].v1].y - v[flist[i].v0].y;   v1.z = v[flist[i].v1].z - v[flist[i].v0].z;
		v2.x = v[flist[i].v2].x - v[flist[i].v0].x;  v1.y = v[flist[i].v2].y - v[flist[i].v0].y;   v1.z = v[flist[i].v2].z - v[flist[i].v0].z;

		norm.x = v1.y*v2.z - v2.y*v1.z;
		norm.y = v1.z*v2.x - v2.z*v1.x;
		norm.z = v1.x*v2.y - v2.x*v1.y;

		nme = sqrtf(norm.x*norm.x + norm.y*norm.y + norm.z*norm.z);
		norm.x /= nme;    norm.y /= nme;    norm.z /= nme;
		thetas[i] = acosf(norm.z);
	}
}

initGL() { 
	GLenum gerr;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective (60, 1800.0f / 900.0f, zNear, 100.0);

	glMatrixMode( GL_MODELVIEW ); 
	glLoadIdentity();

	if ( (gerr = glGetError()) != GL_NO_ERROR) {
		fprintf(stderr, "OpenGL init failed: error = %d\n", gerr);
		exit(1);
	} 
}


update() {
	register int i;
}


struct vertex
*getNorm(a,b,c) 
struct vertex *a,*b,*c;
{
	struct vertex v1,v2,norm;
	float nme;

	v1.x = b->x - a->x;  v1.y = b->y - a->y;   v1.z = b->z - a->z;
	v2.x = c->x - a->x;  v1.y = c->y - a->y;   v1.z = c->z - a->z;

	norm.x = v1.y*v2.z - v2.y*v1.z;
	norm.y = v1.z*v2.x - v2.z*v1.x;
	norm.z = v1.x*v2.y - v2.x*v1.y;

	nme = sqrtf(norm.x*norm.x + norm.y*norm.y + norm.z*norm.z);
	norm.x /= nme;    norm.y /= nme;    norm.z /= nme;
memcpy((void *) &nret, (void *) &norm, sizeof(nret));
	return(&nret);
}
 

void
render() {
	register int i;
	struct vertex n;
	float theta;

	glClearColor(0.9, 0.0, 0.0, 0.5 );
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	for (i=0; i< facecnt; i++) {

//if ((thetas[i] < -1.57f) || (thetas[i] > 1.57f)) {
			glColor3f(thetas[i]/3.14159f, thetas[i]/3.14159f, thetas[i]/3.14159f);
			glVertex3f(v[flist[i].v0].x, v[flist[i].v0].y, v[flist[i].v0].z);

			if (i) glColor3f(0.3f*thetas[i-1]/3.14159f, thetas[i-1]/3.14159f, thetas[i-1]/3.14159f);
			glVertex3f(v[flist[i].v1].x, v[flist[i].v1].y, v[flist[i].v1].z);

			if (i>1)glColor3f(0.2f*thetas[i-2]/3.14159f, 0.3f*thetas[i-2]/3.14159f, thetas[i-2]/3.14159f);
			glVertex3f(v[flist[i].v2].x, v[flist[i].v2].y, v[flist[i].v2].z);
		}
	//}
	glEnd();
	glutSwapBuffers();
}

void
mloop(v)
int v;
{
printf("in mainloop\n");
	update();
	render();

	glutTimerFunc(1000/60, mloop, v);
}

void mf (btn, state, x, y)
int btn,state,x,y;
{
	int i;
	struct vertex v1,v2,norm;
	float nme;
printf("in mousecallback, btn=%d %d  %d  %d\n", btn, state,x,y);
	switch (btn) {
		case 0: glRotatef(4.0f,0.0f,1.0f,0.5f);
			break;
		case 2: glRotatef(4.0f,1.0f,0.0f,0.5f);
			break;
		case 3: glScalef(1.1f, 1.1f, 1.1f);
			break;
		case 4: glScalef(0.9f, 0.9f, 0.9f);
			break;

	}
	for (i=0; i< facecnt; i++) {
		v1.x = v[flist[i].v1].x - v[flist[i].v0].x;  v1.y = v[flist[i].v1].y - v[flist[i].v0].y;   v1.z = v[flist[i].v1].z - v[flist[i].v0].z;
		v2.x = v[flist[i].v2].x - v[flist[i].v0].x;  v1.y = v[flist[i].v2].y - v[flist[i].v0].y;   v1.z = v[flist[i].v2].z - v[flist[i].v0].z;

		norm.x = v1.y*v2.z - v2.y*v1.z;
		norm.y = v1.z*v2.x - v2.z*v1.x;
		norm.z = v1.x*v2.y - v2.x*v1.y;

		nme = sqrtf(norm.x*norm.x + norm.y*norm.y + norm.z*norm.z);
		norm.x /= nme;    norm.y /= nme;    norm.z /= nme;
		thetas[i] = acosf(norm.z);
	}
}




main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	init(argv);

	glutInit(&argc, argv);

	initGL();

	glutInitContextVersion(2, 1);

	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1800,900);
	glutCreateWindow("example 1");
	glutMouseFunc(mf);
	glutDisplayFunc(render);

	glutTimerFunc(1000/60, mloop, 0); /* 60 == frame rate */
	
	glScalef(8.0f,8.0f,8.0f);
	glTranslatef(0.0f, -0.1f, 0.0f);
	glutMainLoop();
}

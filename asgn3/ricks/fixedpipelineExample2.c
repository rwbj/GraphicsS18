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



update() {
	register int i;
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

			glVertex3f(v[flist[i].v0].x, v[flist[i].v0].y, v[flist[i].v0].z);
			glVertex3f(v[flist[i].v1].x, v[flist[i].v1].y, v[flist[i].v1].z);
			glVertex3f(v[flist[i].v2].x, v[flist[i].v2].y, v[flist[i].v2].z);
	}
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
	}
}




main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	glutInit(&argc, argv);

	glutInitContextVersion(2, 1);

	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1800,900);
	glutCreateWindow("example 1");
	glutMouseFunc(mf);
	glutDisplayFunc(render);
	glutTimerFunc(1000/60, mloop, 0); /* 60 == frame rate */
	
	glutMainLoop();
}

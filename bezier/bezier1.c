#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "math_3d.h"

typedef struct _pt {
	float x;
	float y;
} Point;

vec3_t *p;
float stepSize = 0.05;

vec3_t bezierPt(vec3_t b0, vec3_t b1, vec3_t b2, vec3_t b3, float t){
    vec3_t tp;
    tp.x = pow(1-t,3)*b0.x + 3*pow(1-t,2)*t*b1.x + 3*(1-t)*pow(t,2)*b2.x + pow(t,3)*b3.x;
    tp.y = pow(1-t,3)*b0.y + 3*pow(1-t,2)*t*b1.y + 3*(1-t)*pow(t,2)*b2.y + pow(t,3)*b3.y;
    tp.z = 0.0f;
    return tp;
}

void display(void){
    vec3_t last, next;
    glClearColor(0.0, 0.0, 0.1, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.7 ,0.0);
    for (float t = stepSize; t < 1.0f; t+=stepSize){
        last = bezierPt(p[0],p[1],p[2],p[3],t-stepSize);
        next = bezierPt(p[0],p[1],p[2],p[3],t);
        printf("t = %f\nlast\t= %f\t%f\t%f\nnext\t= %f\t%f\t%f\n", t, last.x, last.y, last.z, next.x, next.y, next.z);
        glVertex3f(last.x, last.y, last.z);
        glVertex3f(next.x, next.y, next.z);
    }
    /*glVertex3f(0.75f, 0.6803f, 0.0f);
    glVertex3f(0.25f, -0.2112f, 0.0f);/*
    glEnd ();
    /*glBegin(GL_POINT);
    glVertex3f();
    glEnd();//*/
    glFlush();
    glutSwapBuffers();
}

void loop(){
    display();
    glutTimerFunc(1000/60, loop, 0);
}


int main(int argc, char **argv, char **envp){
    p = malloc(sizeof(vec3_t)*16);
    for(int i = 0; i < 16; i++){
        p[i].x =(float)(i%4)*(-0.5f)+0.75f;
        p[i].y = 2*(float)rand()/RAND_MAX - 1.0f;
        p[i].z = 0.0f;
        printf("p[%d] \t= %f\t%f\t%f\n",i, p[i].x, p[i].y, p[i].z);
    }

	float x,y,x2,y2,x3,y3,xn,yn,t;

	/*for (t=0.0; t<=1.0;  t+=stepSize) {
        x = (1.0-t)*p0.x + t*p1.x;
		y = (1.0-t)*p0.y + t*p1.y;

		x2 = (1.0-t)*p1.x + t*p2.x;
		y2 = (1.0-t)*p1.y + t*p2.y;

        

        xn = (1.0-t)*x + t*x2;
        yn = (1.0-t)*y + t*y2;


        printf("%f %f\n", xn,yn);
	}*/

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
    glutCreateWindow (argv[0]);
    //glutReshapeFunc (reshape);
    //glutKeyboardFunc (keyboard);
    glutDisplayFunc (display);
    //glutTimerFunc(1000/60, loop, 0);
    glutMainLoop();
}

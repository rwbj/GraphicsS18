#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>

float t = 0;

void init(void)
{
    float t;
    t = 0.0;
}


/*  Draw 2 diagonal lines to form an X
 */
void display(void)
{
    glClearColor(0.0, 0.2, 0.4, 0.5 );
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1,0.0,0.0);
        glVertex3f(-0.5,0.5,0);
        glVertex3f(0.5,0.1+t,0);
        glVertex3f(-0.5,-0.5,0);
        glVertex3f(-0.5,0.5,0);
        glVertex3f(-0.6,0.8,0);
        glVertex3f(-0.7,0.4,0);
    glEnd ();
    glFlush();
    glutSwapBuffers();
}

void loop(){
    t = t -0.1;
    display();
    glutTimerFunc(1000, loop, 0);
}

void reshape(int w, int h)
{
  printf("reshape\n");
}

void keyboard(unsigned char key, int x, int y)
{
	printf("keypress: %d    x: %d    y: %d\n", key, x, y);
    /*if (key==askii) transform;*/
}



main(argc, argv, envp)
int argc;
char **argv, **envp;
{
    glutInit(&argc, argv);
    //glutInitDisplayMode (GLUT_SINGLE | GLUT_INDEX);
    //glutInitDisplayMode (GLUT_SINGLE);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
    //glScalef(8.0f,8.0f,8.0f);
    glutCreateWindow (argv[0]);
    init();

    glutReshapeFunc (reshape);
    glutKeyboardFunc (keyboard);
    glutDisplayFunc (display);

    glutTimerFunc(1000, loop, 0);

    //glScalef(8.0f,8.0f,8.0f);
	//glTranslatef(0.0f, -0.1f, 0.0f);
    glutMainLoop();
}

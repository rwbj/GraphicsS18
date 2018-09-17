#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>

void init(void)
{
}


/*  Draw 2 diagonal lines to form an X
 */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin (GL_LINES);
      glVertex2f (0.25, 0.25);
      glVertex2f (-0.25, -0.25);
   glEnd ();
   glFlush();
}

void reshape(int w, int h)
{
  printf("reshape\n");
}

void keyboard(unsigned char key, int x, int y)
{
	printf("keypress: %d    x: %d    y: %d\n", key, x, y);

}



main(argc, argv, envp)
int argc;
char **argv, **envp;
{
   glutInit(&argc, argv);
   //glutInitDisplayMode (GLUT_SINGLE | GLUT_INDEX);
   //glutInitDisplayMode (GLUT_SINGLE);
   glutInitWindowSize (400, 400);
   glutCreateWindow (argv[0]);
   init();
   glutReshapeFunc (reshape);
   glutKeyboardFunc (keyboard);
   glutDisplayFunc (display);
   glutMainLoop();
}

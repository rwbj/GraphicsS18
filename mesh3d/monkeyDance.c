//this is where the monkey dances
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>

typedef struct _m41 {
	float x;
	float y;
	float z;
	float w;
} m41;

typedef struct _m44 {
	float x0,y0,z0,w0;
	float x1,y1,z1,w1;
	float x2,y2,z2,w2;
	float x3,y3,z3,w3;
} m44;

typedef struct _face {
	int v1, v2, v3;
} face;

m44 state;


int vCount;
int fCount;
m41 *vList;
face *fList;

int readfile(char *fileName){
    
    char buff[1024];
    FILE *f;

    f = fopen(fileName,"r");
    fgets(buff, sizeof(buff), f);
    vCount = atoi(buff);
    printf("vCount: %d\n", vCount);

    /*get verts*/
    vList = calloc(vCount,sizeof(m41));
    char *x, *y, *z;
    float xMax, xMin, yMax, yMin, zMax, zMin;
    xMax = xMin = yMax = yMin = zMax = zMin = 0;
        printf("xmax %f, ymax %f, zmax %f\n",xMax, yMax, zMax);
        printf("xMin %f, yMin %f, zMin %f\n",xMin, yMin, zMin);
        
    for (int i = 0; i < vCount; i++){
        fgets(buff,sizeof(buff),f);
        x = strtok(buff, " ");
        y = strtok(NULL, " ");
        z = strtok(NULL, " ");
        //printf("substings at %d: %s, %s, %s\n", i, x, y, z);

        vList[i].x = atof(x);
        vList[i].y = atof(y);
        vList[i].z = atof(z);
        vList[i].w = 1.0f;
        //printf("split at %d: %f, %f, %f, %f\n",i, vList[i].x, vList[i].y, vList[i].z, vList[i].w);
        
        /*get max & min*/
        if (vList[i].x > xMax) xMax = vList[i].x;
        else if(vList[i].x < xMin) xMin = vList[i].x;
        
        if (vList[i].y > yMax) yMax = vList[i].y;
        else if(vList[i].y < yMin) yMin = vList[i].y;
        
        if (vList[i].z > zMax) zMax = vList[i].z;
        else if(vList[i].z < zMin) zMin = vList[i].z;
    }
    
    //printf("xmax %f, ymax %f, zmax %f\n",xMax, yMax, zMax);
    //printf("xMin %f, yMin %f, zMin %f\n",xMin, yMin, zMin);

    /*center mesh*/
    //code to come

    /*resize verts*/
    if (xMax+xMin < 0.0f) xMax = fabs(xMin);
    if (yMax+yMin < 0.0f) yMax = fabs(yMin);
    if (zMax+zMin < 0.0f) zMax = fabs(zMin);

    float xRatio, yRatio, zRatio;
    xRatio = 1.0f/xMax;
    yRatio = 1.0f/yMax;
    zRatio = 1.0f/zMax;
    printf("strech by: x = %f, y = %f, z = %f\n",xRatio, yRatio, zRatio);
    for (int i = 0; i < vCount; i++){
        vList[i].x = vList[i].x*xRatio;
        vList[i].y = vList[i].y*yRatio;
        vList[i].z = vList[i].z*zRatio;
    }

    /*get faces*/
    fgets(buff, sizeof(buff), f);
    fCount = atoi(buff);
    fList = calloc(fCount,sizeof(face));

    for (int i = 0; i < fCount; i++){
        fgets(buff,sizeof(buff),f);
        if(atoi(strtok(buff, " "))==3){
            fList[i].v1 = atoi(strtok(NULL, " "));
            fList[i].v2 = atoi(strtok(NULL, " "));
            fList[i].v3 = atoi(strtok(NULL, " "));
        }else{printf("skipped face[%d]: not a 3 vert face\n", i);}
    }
}

int multMx(m44 tMx, m41 *v){
    v->x = tMx.x0*v->x + tMx.y0*v->y + tMx.z0*v->z + tMx.w0*v->w;
    v->y = tMx.x1*v->x + tMx.y1*v->y + tMx.z1*v->z + tMx.w1*v->w;
    v->z = tMx.x2*v->x + tMx.y2*v->y + tMx.z2*v->z + tMx.w2*v->w;
    v->w = tMx.x3*v->x + tMx.y3*v->y + tMx.z3*v->z + tMx.w3*v->w;
}

int rotate(float ang, char axis){
    m44 rx, ry, rz;

    rx.x0 = 1; rx.y0 = 0; rx.z0 = 0; rx.w0 = 0;
    rx.x1 = 0; rx.y1 = cos(ang); rx.z1 = -sin(ang); rx.w1 = 0; //compile w/ -lm
    rx.x2 = 0; rx.y2 = sin(ang); rx.z2 = cos(ang); rx.w2 = 0;
    rx.x3 = 0; rx.y3 = 0; rx.z3 = 0; rx.w3 = 1;

    ry.x0 = cos(ang); ry.y0 = 0; ry.z0 = sin(ang); ry.w0 = 0;
    ry.x1 = 0; ry.y1 = 1; ry.z1 = 0; ry.w1 = 0;
    ry.x2 = -sin(ang); ry.y2 = 0; ry.z2 = cos(ang); ry.w2 = 0;
    ry.x3 = 0; ry.y3 = 0; ry.z3 = 0; ry.w3 = 1;

    rz.x0 = cos(ang); rz.y0 = -sin(ang); rz.z0 = 0; rz.w0 = 0;
    rz.x1 = sin(ang); rz.y1 = cos(ang); rz.z1 = 0; rz.w1 = 0;
    rz.x2 = 0; rz.y2 = 0; rz.z2 = 1; rz.w2 = 0;
    rz.x3 = 0; rz.y3 = 0; rz.z3 = 0; rz.w3 = 1;

    switch(axis){
        case 'x':
            for (int i = 0; i < vCount; i++){
                multMx(rx, &(vList[i]));
            }
            break;

        case 'y':
            for (int i = 0; i < vCount; i++){
                multMx(ry, &(vList[i]));
            }
            break;

        case 'z':
            for (int i = 0; i < vCount; i++){
                multMx(rz, &(vList[i]));
            }
            break;

        default:
            break;
    }
}

int translate(float dx, float dy, float dz){
    m44 t;

    t.x0 = 1; t.y0 = 0; t.z0 = 0; t.w0 = dx;
    t.x1 = 0; t.y1 = 1; t.z1 = 0; t.w1 = dy;
    t.x2 = 0; t.y2 = 0; t.z2 = 1; t.w2 = dz;
    t.x3 = 0; t.y3 = 0; t.z3 = 0; t.w3 = 1;

    for (int i = 0; i < vCount; i++){
        multMx(t, &(vList[i]));
    }
}

int scale(float dx, float dy, float dz){
    m44 s;

    s.x0 = dx; s.y0 = 0; s.z0 = 0; s.w0 = 0;
    s.x1 = 0; s.y1 = dy; s.z1 = 0; s.w1 = 0;
    s.x2 = 0; s.y2 = 0; s.z2 = dz; s.w2 = 0;
    s.x3 = 0; s.y3 = 0; s.z3 = 0; s.w3 = 1;

    for (int i = 0; i < vCount; i++){
        multMx(s, &(vList[i]));
    }
}

int printVerts(){
    for(int i = 0; i < vCount; i++){
        printf("vert %d: %f, %f, %f, %f\n",i, vList[i].x, vList[i].y, vList[i].z, vList[i].w);
    }
}

int printFaces(){
    for(int i = 0; i < fCount; i++){
        printf("face %d: %d, %d, %d\n",i, fList[i].v1, fList[i].v2, fList[i].v3);
    }
}

void display(void)
{
    glClearColor(0.0, 0.2, 0.4, 0.5 );
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < fCount; i++){
        if (i%3 == 0) glColor3f(0.7f,0.0f,0.3f);
        else if (i%3 > 1) glColor3f(0.7f,0.15f,0.15f); 
        else glColor3f(0.7f,0.3f,0.0f);
        glVertex3f(vList[fList[i].v1].x, vList[fList[i].v1].y, vList[fList[i].v1].z);
        glVertex3f(vList[fList[i].v2].x, vList[fList[i].v2].y, vList[fList[i].v2].z);
        glVertex3f(vList[fList[i].v3].x, vList[fList[i].v3].y, vList[fList[i].v3].z);
    }
    glEnd ();
    glFlush();
    glutSwapBuffers();
}

void loop(){
    display();
    glutTimerFunc(1000/60, loop, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	printf("keypress: %d    x: %d    y: %d\n", key, x, y);
    switch(key){
        /*rotate*/
        case 119: //w = +rx
            rotate(0.1f,'x');
            break;
        case 97: //a = -ry
            rotate(-0.1f,'y');
            break;
        case 115: //s = -rx
            rotate(-0.1f,'x');
            break;
        case 100: //d = +ry
            rotate(0.1f,'y');
            break;
        case 113: //q = -rz
            rotate(-0.1f,'z');
            break;
        case 101: //e = +rz
            rotate(0.1f,'z');
            break;
        /*treanslate*/
        case 87: //W
            translate(0.0f,0.02f,0.0f);
            break;
        case 65: //A
            translate(-0.02f,0.0f,0.0f);
            break;
        case 83: //S
            translate(0.0f,-0.02f,0.0f);
            break;
        case 68: //D
            translate(0.02f,0.0f,0.0f);
            break;
        case 81: //Q
            translate(0.0f,0.0f,0.1f);
            break;
        case 69: //E
            translate(0.0f,0.0f,-0.1f);
            break;
        /*scale*/
        case 49: //1
            scale(1.1f,1.1f,1.1f);
            break;
        case 50: //2
            scale(1.1f,1.0f,1.0f);
            break;
        case 51: //3
            scale(1.0f,1.1f,1.0f);
            break;
        case 52: //4
            scale(1.0f,1.0f,1.1f);
            break;
        case 33: //!
            scale(0.9f,0.9f,0.9f);
            break;
        case 64: //@
            scale(0.9f,1.0f,1.0f);
            break;
        case 35: //#
            scale(1.0f,0.9f,1.0f);
            break;
        case 36: //$
            scale(1.0f,1.0f,0.9f);
            break;
        default:
            break;
    }
}

main(argc, argv, envp)
int argc;
char **argv, **envp;
{
    state.x0 = 1; state.y0 = 0; state.z0 = 0; state.w0 = 0;
    state.x1 = 0; state.y1 = 1; state.z1 = 0; state.w1 = 0;
    state.x2 = 0; state.y2 = 0; state.z2 = 1; state.w2 = 0;
    state.x3 = 0; state.y3 = 0; state.z3 = 0; state.w3 = 1;
    /*read in model*/
    readfile("model.ply");
    printf("this is main\n");
    //printVerts();
    //printFaces();
    printf("vCount:%d ,fCount:%d\n", vCount, fCount);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
    glutCreateWindow (argv[0]);

    //glutReshapeFunc (reshape);
    glutKeyboardFunc (keyboard);
    glutDisplayFunc (display);

    glutTimerFunc(1000/60, loop, 0);
    glutMainLoop();
}

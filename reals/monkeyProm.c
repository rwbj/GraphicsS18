//this is where the monkey dances
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "math_3d.h"


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

mat4_t compound;

vec3_t center;

int vCount;
int fCount;
vec3_t *vList, *vListRaw;
face *fList;

int readfile(char *fileName){
    
    char buff[1024];
    FILE *f;

    f = fopen(fileName,"r");
    fgets(buff, sizeof(buff), f);
    vCount = atoi(buff);
    printf("vCount: %d\n", vCount);

    /*get verts*/
    vList = calloc(vCount,sizeof(vec3_t));
    vListRaw = calloc(vCount, sizeof(vec3_t));
    char *x, *y, *z;
    float xMax, xMin, yMax, yMin, zMax, zMin, xSum, ySum, zSum;
    /*xMax = xMin = yMax = yMin = zMax = zMin = 0; //this should be set to the first vec3
        printf("xmax %f, ymax %f, zmax %f\n",xMax, yMax, zMax);
        printf("xMin %f, yMin %f, zMin %f\n",xMin, yMin, zMin);*/

    for (int i = 0; i < vCount-1; i++){
        fgets(buff,sizeof(buff),f);
        x = strtok(buff, " ");
        y = strtok(NULL, " ");
        z = strtok(NULL, " ");
        //printf("substings at %d: %s, %s, %s\n", i, x, y, z);

        vListRaw[i].x = atof(x); //doint need to set vList yet
        vListRaw[i].y = atof(y);
        vListRaw[i].z = atof(z);
        //vList[i].w = 1.0f;

        //printf("split at %d: %f, %f, %f, %f\n",i, vList[i].x, vList[i].y, vList[i].z, vList[i].w);
        
        /*get max & min*/
        if (i=0){
            xSum = xMin = xMax = vListRaw[i].x;
            ySum = yMin = yMax = vListRaw[i].y;
            zSum = zMin = zMax = vListRaw[i].z;
        }
        else{
            xSum += vListRaw[i].x;
            if (vListRaw[i].x > xMax) xMax = vListRaw[i].x;
            else if(vListRaw[i].x < xMin) xMin = vListRaw[i].x;
            ySum += vListRaw[i].y;
            if (vListRaw[i].y > yMax) yMax = vListRaw[i].y;
            else if(vListRaw[i].y < yMin) yMin = vListRaw[i].y;
            zSum += vListRaw[i].z;
            if (vListRaw[i].z > zMax) zMax = vListRaw[i].z;
            else if(vListRaw[i].z < zMin) zMin = vListRaw[i].z;
        }
    }
    
    //printf("xmax %f, ymax %f, zmax %f\n",xMax, yMax, zMax);
    //printf("xMin %f, yMin %f, zMin %f\n",xMin, yMin, zMin);

    /*center mesh*/
    center.x = xSum/vCount;
    center.y = ySum/vCount;
    center.z = zSum/vCount;

    /*resize verts*/
    if (xMax+xMin < 0.0f) xMax = fabs(xMin);
    if (yMax+yMin < 0.0f) yMax = fabs(yMin);
    if (zMax+zMin < 0.0f) zMax = fabs(zMin);

    /*float xRatio, yRatio, zRatio;
    xRatio = 1.0f/xMax;
    yRatio = 1.0f/yMax;
    zRatio = 1.0f/zMax;
    printf("strech by: x = %f, y = %f, z = %f\n",xRatio, yRatio, zRatio);
    for (int i = 0; i < vCount; i++){
        vList[i].x = vList[i].x*xRatio;
        vList[i].y = vList[i].y*yRatio;
        vList[i].z = vList[i].z*zRatio;
    }*/

    float scale = xMax;
    if (yMax > scale) scale = yMax;
    if (zMax > scale) scale = zMax;
    /*for (int i = 0; i < vCount; i++){
        vList[i].x = vList[i].x / scale;
        vList[i].y = vList[i].y / scale;
        vList[i].z = vList[i].z / scale;
    }*/

    compound = mat4(
        1/scale, 0.0f, 0.0f, -center.x,
        0.0f, 1/scale, 0.0f, -center.y,
        0.0f, 0.0f, 1/scale, -center.z,
        0.0f, 0.0f, 0.0f, 1.0f);

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

int multMxVt(m44 tMx, m41 *v){
    v->x = tMx.x0*v->x + tMx.y0*v->y + tMx.z0*v->z + tMx.w0*v->w;
    v->y = tMx.x1*v->x + tMx.y1*v->y + tMx.z1*v->z + tMx.w1*v->w;
    v->z = tMx.x2*v->x + tMx.y2*v->y + tMx.z2*v->z + tMx.w2*v->w;
    v->w = tMx.x3*v->x + tMx.y3*v->y + tMx.z3*v->z + tMx.w3*v->w;
}

m44 multMxMx(m44 mx1, m44 mx2){
    m44 prod;
    m41 v0, v1, v2, v3;
    v0.x = mx2.x0; v0.y = mx2.y0; v0.z = mx2.z0; v0.w = mx2.w0;
    v1.x = mx2.x1; v1.y = mx2.y1; v1.z = mx2.z1; v1.w = mx2.w1;
    v2.x = mx2.x2; v2.y = mx2.y2; v2.z = mx2.z2; v2.w = mx2.w2;
    v3.x = mx3.x3; v3.y = mx3.y3; v3.z = mx3.z3; v3.w = mx3.w3;
    multMxVt(mx1, &v0);
    multMxVt(mx1, &v1);
    multMxVt(mx1, &v2);
    multMxVt(mx1, &v3);
    prod.x0 = v0.x; prod.y0 = v0.y; prod.z0 = v0.z; prod.w0 = v0.w;
    prod.x1 = v1.x; prod.y1 = v1.y; prod.z1 = v1.z; prod.w1 = v1.w;
    prod.x2 = v2.x; prod.y2 = v2.y; prod.z2 = v2.z; prod.w2 = v2.w;
    prod.x3 = v3.x; prod.y3 = v3.y; prod.z3 = v3.z; prod.w3 = v3.w;
    return prod;
}

vec3_t surfNorm(vec3_t v1, vec3_t v2, vec3_t v3){
    vec3_t n = vec3(
        (v2.y - v1.y)*(v3.z - v1.z) - (v3.y - v1.y)*(v2.z - v1.z),
        (v2.z - v1.z)*(v3.x - v1.x) - (v3.z - v1.z)*(v2.x - v1.x),
        (v2.x - v1.x)*(v3.y - v1.y) - (v3.x - v1.x)*(v2.y - v1.y));
    return n;
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
                multMxVt(rx, &(vList[i]));
            }
            break;

        case 'y':
            for (int i = 0; i < vCount; i++){
                multMxVt(ry, &(vList[i]));
            }
            break;

        case 'z':
            for (int i = 0; i < vCount; i++){
                multMxVt(rz, &(vList[i]));
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
        multMxVt(t, &(vList[i]));
    }
}

int scale(float dx, float dy, float dz){
    m44 s;

    s.x0 = dx; s.y0 = 0; s.z0 = 0; s.w0 = 0;
    s.x1 = 0; s.y1 = dy; s.z1 = 0; s.w1 = 0;
    s.x2 = 0; s.y2 = 0; s.z2 = dz; s.w2 = 0;
    s.x3 = 0; s.y3 = 0; s.z3 = 0; s.w3 = 1;

    for (int i = 0; i < vCount; i++){
        multMxVt(s, &(vList[i]));
    }
}

int printVerts(){
    for(int i = 0; i < vCount; i++){
        printf("vert %d: %f, %f, %f\n",i, vList[i].x, vList[i].y, vList[i].z);
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
    for(int i = 0; i<vCount; i++){
        vList[i] = m4_mul_pos (compound, vListRaw[i]);
    }
    display(); /* would it be faster to run disply before compound transformations? latency of input vs of responce...*/
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
            translate(0.0f,0.0f,0.01f);
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

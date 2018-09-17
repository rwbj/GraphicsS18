#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // compile with -lm

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

int vCount;
int fCount;
m41 *vList;
face *fList;

/*
char **readply(char *filename){
    char **list;
    list = calloc(5,sizeof(char *));
    //list[0] = strdup("thing 0");
    FILE *f;
    f = fopen(filename,"r");
    char buff[1024];
    vCount = atoi(fgets(buff, sizeof(buff), f));
    printf("vCount = %d\n", vCount);
    int c = 0;
    while(c<vCount){
        fgets(buff, sizeof(buff), f);
        c++;
        list[c] = buff;
        printf("%s",list[c]);
    }
    fclose(f);
    return list;
}*/

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
    float max, min;
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
        if (vList[i].x > max) max = vList[i].x;
        else if(vList[i].x < min) min = vList[i].x;
        
        if (vList[i].y > max) max = vList[i].y;
        else if(vList[i].y < min) min = vList[i].y;
        
        if (vList[i].z > max) max = vList[i].z;
        else if(vList[i].z < min) min = vList[i].z;
    }

    /*resize verts*/
    if (max+min < 0.0f) max = fabs(min);
    float sizeRatio;
    sizeRatio = 1.0f/max;
    for (int i = 0; i < vCount; i++){
        vList[i].x = vList[i].x*sizeRatio;
        vList[i].y = vList[i].y*sizeRatio;
        vList[i].z = vList[i].z*sizeRatio;
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

void scale(float dx, float dy, float dz){
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

int main(int argc, char **argv, char **envp){
    //readply("test.ply");
    readfile("model.ply");
    printf("this is main\n");
    /*int c = 0;
    while(vList[c]){
        printf("%s\n",vList[c]);
        c++;
    }*/
    //scale(2.0f,3.0f,0.5f);
    //translate(2.0f,3.0f,0.5f);
    //rotate(0.2f,'x');
    printVerts();
    //printFaces();
    printf("vCount:%d ,fCount:%d\n", vCount, fCount);

}


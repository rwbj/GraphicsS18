#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

m44 compound;

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
    v3.x = mx2.x3; v3.y = mx2.y3; v3.z = mx2.z3; v3.w = mx2.w3;
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

mat4_t theBetterOne(mat4_t l, mat4_t r){
    return m4_mul(l,r);
}

int printMx44(m44 m){
    printf("this is the matrix:\n%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f\n%f\t%f\t%f\t%f\n",
        m.x0,m.y0,m.z0,m.w0,
        m.x1,m.y1,m.z1,m.w1,
        m.x2,m.y2,m.z2,m.w2,
        m.x3,m.y3,m.z3,m.w3);
}

int main(){
    /*compound.x0 = 7; compound.y0 = 8; compound.z0 = 1; compound.w0 = 9;
    compound.x1 = 0.6; compound.y1 = .4; compound.z1 = 0.5; compound.w1 = 100;
    compound.x2 = 56; compound.y2 = 2; compound.z2 = .02; compound.w2 = 23;
    compound.x3 = 7; compound.y3 = 3; compound.z3 = 0.5; compound.w3 = 4;
    m44 test;
    test.x0 = 1.2; test.y0 = 1.3; test.z0 = 1.4; test.w0 = 1.5;
    test.x1 = 1.6; test.y1 = 1.7; test.z1 = 1.8; test.w1 = 1.9;
    test.x2 = 2; test.y2 = 2.1; test.z2 = 2.2; test.w2 = 2.3;
    test.x3 = 2.4; test.y3 = 2.5; test.z3 = 2.6; test.w3 = 2.7;
    //result = multMxMx(compound, test);
    //printMx44(result);    */
    mat4_t res, left, right;
    left = mat4(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
    right = mat4(17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32);
    //res = theBetterOne(left,right);
    /*right = mat4(
        1,0,0,2,
        0,1,0,3,
        0,0,1,4,
        0,0,0,1);
    left = mat4(
        1,0,0,0,
        0,1,2,0,
        0,0,1,0,
        0,0,0,1);*/
    res = m4_mul(left,right);
    m4_print(res);
    /*for(int i = 0; i<4; i++){
        printf("%f\t%f\t%f\t%f\n",res.m[i][0],res.m[i][1],res.m[i][2],res.m[i][3]);
    }*/
}
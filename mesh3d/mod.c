#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


/* multiply transform matrix by vertex, store answer in vertex */
void
mmul(m44 transform,  m41 *vertex)
{
	m41 vert, newvert;
	vert = *vertex;
	newvert.x = transform.x0*vert.x + transform.y0*vert.y  +  transform.z0*vert.z + transform.w0*vert.w;
	newvert.y = transform.x1*vert.x + transform.y1*vert.y  +  transform.z1*vert.z + transform.w1*vert.w;
	newvert.z = transform.x2*vert.x + transform.y2*vert.y  +  transform.z2*vert.z + transform.w2*vert.w;
	newvert.w = transform.x3*vert.x + transform.y3*vert.y  +  transform.z3*vert.z + transform.w3*vert.w;

	memcpy(vertex, &newvert, sizeof(newvert));
}

main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	float x,y,z;
	char buf[1024];
	int i, nvert, nface, three;
	m41 *vertexList;
	face *faceList;
    FILE *file;

	m44 scaleMatrix;
	scaleMatrix.x0=2.0f;  scaleMatrix.y0=0.0f;  scaleMatrix.z0=0.0f;   scaleMatrix.w0=0.0f;
	scaleMatrix.x1=0.0f;  scaleMatrix.y1=2.0f;  scaleMatrix.z1=0.0f;   scaleMatrix.w1=0.0f;
	scaleMatrix.x2=0.0f;  scaleMatrix.y2=0.0f;  scaleMatrix.z2=2.0f;   scaleMatrix.w2=0.0f;
	scaleMatrix.x3=0.0f;  scaleMatrix.y3=0.0f;  scaleMatrix.z3=0.0f;   scaleMatrix.w3=1.0f;

	gets(buf);
	nvert = atoi(buf); //read as an int
	vertexList = calloc(nvert, sizeof(struct _m41)); //creat space for vert array

	for (i=0; i<nvert; i++) {
		gets(buf);
		sscanf(buf, "%f %f %f", &(vertexList[i].x), &(vertexList[i].y), &(vertexList[i].z));
		vertexList[i].w = 1.0f;
	}

	gets(buf); //now reads in the number of faces
	nface = atoi(buf); //to int
	faceList = calloc(nface, sizeof(struct _face));

	for (i=0; i<nface; i++){
		gets(buf);
		sscanf(buf, "%d %d %d %d", &three, &(faceList[i].v1), &(faceList[i].v2), &(faceList[i].v3));
	}

printf("%d vertices\n", nvert);
printf("%d faces\n", nface);
sleep(5);
for (i=0; i<nvert; i++)
	printf("vertex[%d] = %f %f %f\n", i, vertexList[i].x, vertexList[i].y, vertexList[i].z);
for (i=0; i<nface; i++)
	printf("face[%d] = %d %d %d\n", i, faceList[i].v1, faceList[i].v2, faceList[i].v3);

printf("\n\nscaled:\n");
sleep(2);

for (i=0; i<nvert; i++)
	mmul(scaleMatrix, &(vertexList[i]));

for (i=0; i<nvert; i++)
	printf("vertex[%d] = %f %f %f\n", i, vertexList[i].x, vertexList[i].y, vertexList[i].z);
}



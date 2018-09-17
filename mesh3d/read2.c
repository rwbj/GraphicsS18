#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct vert{
    float x,y,z;
}

struct face{
    int v1,v2,v3;
}

struct matrix{
    float m00,m01,m02,m03;
    float m10,m11,m12,m13;
    float m20,m21,m22,m23;
    float m30,m31,m32,m33;
}

char **readply(char *filename){
    char **verts, **faces;
    int vertNum, faceNum;
    FILE *f;
    char buff[1024];

    f = fopen(filename,"r");
    vertNum = atoi(buff);
    list = malloc(vertNum,sizeof(vert));
    for(int i=0;i<vertNum;i++){
        fgets(buff, sizeof(buff), f);
        list[i] = buff;
        //printf("%s",list[i]);
    }
    fclose(f);
    return list;
}


int main(argc, argv, envp)
int argc;
char **argv, **envp;{
    char **list;
    list = readply("test.txt");
    printf("this is main\n");
    for(int i=0;i<5;i++){
        printf("%s\n",list[i]);
    }
}
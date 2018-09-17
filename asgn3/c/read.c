#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(argc, argv, envp)
int argc;
char **argv, **envp;{
    char **list;
    list = calloc(5,sizeof(char *));
    list[0] = strdup("thing 0");
    FILE *f;
    f = fopen("test.txt","r");
    int c = 0;
    while(c<5){
        char buff[1024];
        fgets(buff, sizeof(buff), f);
        c++;
        list[c] = buff;
        printf("%s",list[c]);
    }
    fclose(f);
}
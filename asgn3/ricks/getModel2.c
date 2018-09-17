#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <endian.h>

#define VSTR "element vertex "
#define FSTR "element face "


//cc -c getModel2.c -lGL -lGLU -lglut -lm

int isbig=0;
int vcnt2=0, fcnt=0;
int isASCII=0;
int fpv=0;	/* floats per vertex */
float minx, miny, minz, maxx, maxy, maxz;


int
readliner(v,f,fp) 
float **v;
int **f;
FILE *fp;
{
	int i,j,nf=0;
	char *s, buf[1024];

	for (i=0; i<vcnt2; i++) {
        	fgets(buf, sizeof(buf), fp);
		s=&(buf[0]);
		(*v)[nf++] = atof(s);
		for (j=1; j<fpv; j++) {
			while (*s != ' ') s++; s++;
			(*v)[nf++] = atof(s);
		}
	}

	for (nf=i=0; i<fcnt; i++) {
        	fgets(buf, sizeof(buf), fp);
		s=&(buf[0]); while(*s != ' ') s++; s++;
		(*f)[nf++] = atoi(s);
		for (j=0; j<2; j++) {
			while (*s != ' ') s++; s++;
			(*f)[nf++] = atoi(s);
		}
	}
}



int
bitsucker(v,f,fp)
float **v;
int **f;
FILE *fp;
{
	float tf;
	int i,k,fvc;
        unsigned char *ptr, u1,u2,u3,u4;

	/* get and conver vertices */
	fread(v, vcnt2, fpv*sizeof(float), fp);
	if (isbig) for (i=0; i<vcnt2; i++) (*v)[i] = be32toh((*v)[i]);

printf("get faces\n");
	for (i=0; i<fcnt; i++) {
		fvc = fgetc(fp);/* has to be triangles only */
		if (fvc != 3) {
			fprintf(stderr, "RED ALERT!, not a triangle: fvc = %d\n", fvc);
			return(-1);
		}

		fread(&k, 1, sizeof(int), fp);
		(*f)[i*3+0] = isbig ? be32toh(k) : k;

		fread(&k, 1, sizeof(int), fp);
		(*f)[i*3+1] = isbig ? be32toh(k) : k;

		fread(&k, 1, sizeof(int), fp);
		(*f)[i*3+2] = isbig ? be32toh(k) : k;
	}


printf("getModel: minmax - %f %f %f   %f %f %f\n", minx,miny,minz,maxx,maxy,maxz);
	fclose(fp);
	return(vcnt2);
}



int
getbounds(v,minx, maxx, miny, maxy, minz, maxz)
float **v;
int *minx, *maxx, *miny, *maxy, *minz, *maxz;
{
	int i;

	for (i=0; i<vcnt2; i++) {
		switch (i%3) {
			case 0:		*maxx = ((*v)[i]>*maxx) ? (*v)[i] : *maxx;
					*minx = ((*v)[i]<*minx) ? (*v)[i] : *minx;
					break;
			case 1:		*maxy = ((*v)[i]>*maxy) ? (*v)[i] : *maxy;
					*miny = ((*v)[i]<*miny) ? (*v)[i] : *miny;
					break;
			case 2:		*maxz = ((*v)[i]>*maxz) ? (*v)[i] : *maxz;
					*minz = ((*v)[i]<*minz) ? (*v)[i] : *minz;
					break;
		}
	}
	return(vcnt2);
}



int
getModel(fname, v, vc, f, fc)
char *fname;
float **v;
int *vc;
int **f;
int *fc;
{
        FILE *fp;

        float tf, fval;
        int k, nextf;
        char buf[1024], *s;
        unsigned int u,i,j;

        minx = miny = minz = 999999999.0f; /* really limits.h, FLT_MAX etc */
        maxx = maxy = maxz = -999999999.0f;

        if (! (fp = fopen(fname, "r"))) {
                fprintf(stderr, "getModel: %s fopen failed, errno= %d\n", fname, errno);
                return(-errno);
        }
        fgets(buf, sizeof(buf), fp);
        s=strchr(buf, '\n'); *s=0;
        if (strcmp(buf, "ply"))
                fprintf(stderr, "getModel: %s does not seem to be a ply file\n", fname);

        while (strcmp(buf, "end_header")) {
                fgets(buf, sizeof(buf), fp);
                s=strchr(buf, '\n'); *s=0;

		if (strncmp(buf, "format", 6) == 0) {
			if (strstr(buf, "ascii"))
				isASCII=1;
		}


                if (s = strstr(buf, "bid_endian")) isbig=1;


		if (strncmp(buf, "property float", 14) == 0) {
			fpv++;
		}

                if (s = strstr(buf, VSTR)) {
                        s += strlen(VSTR);
                        *vc = vcnt2 = atoi(s);
                }

                if (s = strstr(buf, FSTR)) {
                        s += strlen(FSTR);
                        *fc = fcnt = atoi(s);
                }
        }
printf("getModel: vertex count: %d\n", vcnt2);
printf("getModel: face count: %d\n", fcnt);
printf("getModel: isASCII: %d\n", isASCII);
printf("getModel: fpv: %d\n", fpv);



	if ( ((*v) = (float *) malloc(vcnt2 * fpv * sizeof(float))) == (float  *) -1) {
                fprintf(stderr, " malloc failed, errno = %d\n", errno);
                        return(-errno);
        }

	if ( ((*f) = (int *) malloc(fcnt * 3 * sizeof(int))) == (int  *) -1) {
                fprintf(stderr, " malloc failed, errno = %d\n", errno);
                        return(-errno);
        }

	if (isASCII)
		readliner(v,f,fp);
	else
		bitsucker(v,f,fp);
	return(fpv);

}

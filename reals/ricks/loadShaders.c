#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>



loadShaders(vfile, ffile)
char *vfile, *ffile;
{
	FILE *f;
	char buf[1024], cbuf[16384], c2buf[16384]; int ret, pid, ill;

	// Create the shaders
	unsigned int VertexShaderID;
	unsigned int FragmentShaderID;

	VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	/*read the code as giant strings

	 Read the Vertex Shader code from the file  */
	memset(cbuf, 0, sizeof(cbuf));
	memset(buf,0,sizeof(buf));
	f = fopen(vfile, "r");

	while (fgets(buf,  sizeof(buf), f)) {strcat(cbuf, buf); strcat(cbuf, "\n");}
	fclose(f);

	f = fopen(ffile, "r");
	while (fgets(buf,  sizeof(buf), f)) {strcat(c2buf, buf); strcat(c2buf, "\n");}
	fclose(f);


	printf("Compiling vertex shader : %s\n", vfile);
	glShaderSource(VertexShaderID, 1, &cbuf , NULL);
	glCompileShader(VertexShaderID);


	/* Check Vertex Shader */
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &ret);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &ill);
	glGetShaderInfoLog(VertexShaderID, ill, NULL, &buf[0]);
	fprintf(stdout, "%s\n", &buf[0]);


	printf("Compiling fragment shader : %s\n", vfile);
	glShaderSource(FragmentShaderID, 1, &cbuf , NULL);
	glCompileShader(FragmentShaderID);


	/* Check Fragment Shader */
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &ret);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &ill);
	glGetShaderInfoLog(FragmentShaderID, ill, NULL, &buf[0]);
	fprintf(stdout, "%s\n", &buf[0]);




	/* Link  */
	printf("Linking\n");
	pid = glCreateProgram();
	glAttachShader(pid, VertexShaderID);
	glAttachShader(pid, FragmentShaderID);
	glLinkProgram(pid);



/* Check for errors again, then: */



	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
	return pid;
}

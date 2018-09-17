make:
	cc -o monkeyDance monkeyDance.c -lGL -lGLU -lglut /usr/lib/x86_64-linux-gnu/libdrm.a -lm -g
	./monkeyDance


compile:
	cc -o monkeyDance monkeyDance.c -lGL -lGLU -lglut /usr/lib/x86_64-linux-gnu/libdrm.a -lm -g
	
run:
	./monkeyDance

debug:
	gdb ./monkeyDance

prom:
	cc -o monkeyProm monkeyProm.c -lGL -lGLU -lglut /usr/lib/x86_64-linux-gnu/libdrm.a -lm -g
	./monkeyProm

promcomp:
	cc -o monkeyProm monkeyProm.c -lGL -lGLU -lglut /usr/lib/x86_64-linux-gnu/libdrm.a -lm -g

promrun:
	./monkeyProm

promdebug:
	gdb ./monkeyProm

testBuild:
	cc -o testBuild testBuild.c -lGL -lGLU -lglut /usr/lib/x86_64-linux-gnu/libdrm.a -lm -g
	./testBuild

testBuildC:
	cc -o testBuild testBuild.c -lGL -lGLU -lglut /usr/lib/x86_64-linux-gnu/libdrm.a -lm -g

testBuildR:
	./testBuild

testBuildDB:
	gdb ./testBuild
aocltoolset: boardConfig.o compileAOCL.o help.o transmission.o aocltoolset.o
	 gcc -o aocltoolset boardConfig.o compileAOCL.o help.o transmission.o aocltoolset.o

boardConfig.o:	boardConfig.c
		gcc -c boardConfig.c

compileAOCL.o:	compileAOCL.c
		gcc -c compileAOCL.c

help.o:	help.c
		gcc -c help.c

transmission.o:	transmission.c
		gcc -c transmission.c

aocltoolset.o:	aocltoolset.c
		gcc -c aocltoolset.c

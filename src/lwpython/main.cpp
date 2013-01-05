//--------------------------------------------------------- ./main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <direct.h>

#include "Compiler.h"

int main(int argc, char **argv)
{
	Compiler comp;
	comp.compile_file("../input/test.py");
	printf("Press any key to exit.\n");
	getchar();
	return EXIT_SUCCESS;
}

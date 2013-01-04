//--------------------------------------------------------- ./main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <direct.h>

#include "parser.h"

int main(int argc, char **argv)
{
	compiler comp;
	//char cwdbuf[BUFSIZ];
	//char *cwd = getcwd(cwdbuf, BUFSIZ);
	//printf(cwd);
	comp.compile_file("../input/test.py");
	//compile_file(&comp, "..\\input\\test.py");
	getchar();
	return EXIT_SUCCESS;
}

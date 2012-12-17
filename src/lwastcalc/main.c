//--------------------------------------------------------- ./main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int getline(char line[], int max)
{
	int nch = 0;
	int c;
	max = max - 1;			/* leave room for '\0' */

	while((c = getchar()) != EOF) {
		if(c == '\n')
			break;
		if(nch < max)
		{
			line[nch] = c;
			nch = nch + 1;
		}
	}
	if(c == EOF && nch == 0)
		return EOF;

	line[nch] = '\0';
	return nch;
}

int main(int argc, char **argv)
{
	int result;
	calculator calc;
	char buffer[BUFSIZ];
	while(getline(buffer, BUFSIZ) != 0){
		result = eval_string(&calc, buffer);
		printf("expression:  (%s) = %f\n",buffer, calc.answer);
	}
	return EXIT_SUCCESS;
}

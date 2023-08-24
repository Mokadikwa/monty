#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 */

int main(int argc, char *argv[])
{
	const char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	processFile(filename);

	return (EXIT_SUCCESS);
}

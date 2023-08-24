#include "monty.h"

/**
 */

void processFile(const char *filename)
{
	FILE *file = fopen(filename, "r");
	stack_t *stack;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number;

	if (!file)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	line_number = 0;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;

		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		char *token = strtok(line, " ");

		if (token == NULL)
			continue;

		executeInstruction(token, &stack, line_number);
	}
	fclose(file);
}

#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	const char *filename;
	FILE *file;
	char line[512];
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		char opcode[256];

		if (sscanf(line, "%255s", opcode) == 1)
		{
			executeInstruction(opcode, &stack, line_number);
		}
		line_number++;
	}
	fclose(file);
	return (EXIT_SUCCESS);
}

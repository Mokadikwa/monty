#include "monty.h"

/**
 * executeInstruction - Executes the specified opcode
 * @opcode: The opcode to execute
 * @stack: A pointer to the stack
 * @line_number: The line number in the file
 */

void executeInstruction(const char *opcode, stack_t **stack,
		unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
	};

	int num_instructions = sizeof(instructions) / sizeof(instruction_t);

	for (i = 0; i < num_instructions; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

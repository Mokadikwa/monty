#include "monty.h"

/**
 */

void push(stack_t **stack, unsigned int line_number)
{
	char value[256];
	stack_t *new_node;
	size_t i;

	if (scanf("%255s", value) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; value[i] != '\0'; i++)
	{
		if (!isdigit(value[i]) && (i == 0 && value[i] != '-'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new_node = malloc(sizeof(stack_t));

	 if (!new_node)
	 {
		 fprintf(stderr, "Error: malloc failed\n");
		 exit(EXIT_FAILURE);
	 }
	 new_node->n = atoi(value);
	 new_node->prev = NULL;
	 new_node->next = *stack;

	 if (*stack)
	 {
		 (*stack)->prev = new_node;
	 }
	 *stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 */

void executeInstruction(const char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	int num_instructions;

	instruction_t instructions[] = {
		{"push", push},
		 {"pall", pall},
	};
	num_instructions = sizeof
		(instructions) / sizeof
		(instruction_t);

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

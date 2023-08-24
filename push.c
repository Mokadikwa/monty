#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: A pointer to the stack
 * @line_number: The line number in the file
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

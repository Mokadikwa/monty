#include "monty.h"

/**
 */

void push(stack_t **stack, int data)
{

	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = data;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}

/**
 */

int pop(stack_t **stack)
{
	int data;
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "Error: Stack underflow\n");
		exit(EXIT_FAILURE);
	}
	data = (*stack)->n;
	temp = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	return (data);
}

/**
 */

void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * processFile - Process the instructions from a file
 * @filename: The name of the file to process
 */

void processFile(const char *filename)
{
	FILE *file = fopen(filename, "r");
	stack_t *stack;
	char line[512];

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	stack = NULL;

	while (fgets(line, sizeof(line), file))
	{
		char opcode[256];
		int arg;

		if (sscanf(line, "%255s %d", opcode, &arg) == 2)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, arg);
			}
			else
			{
				fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack);
		}
	}
	fclose(file);
}

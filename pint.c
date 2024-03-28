#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


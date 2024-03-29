#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	int len, l;

	len = 0;
	first = *stack;
	while (first)
	{
		first = first->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	l = first->n;
	first->n = first->next->n;
	first->next->n = l;
}

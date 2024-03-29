#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	l = first->n + first->next->n;
	first->next->n = l;
	*stack = first->next;
	free(first);
}

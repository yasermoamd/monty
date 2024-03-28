#include "monty.h"

/**
 * pop - deletes the element at the top of the stack.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}
	*stack = head->next;
	free(head);
}


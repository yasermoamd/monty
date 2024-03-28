#include "monty.h"

/**
 * pall - prints all the values on the stack, from the top.
 * @stack: the head of the stack
 * @line_number: the file's line
 * Return: nothing
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	UNUSED(line_number);
	head = *stack;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}


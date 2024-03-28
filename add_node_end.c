#include "monty.h"
/**
 * add_node_end - add node to the tail stack
 * @n: new_value
 * @stack: head of the stack
 * Return: no return
*/
void add_node_end(stack_t **stack, int n)
{
	stack_t *new_node, *head;

	head = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (head)
	{
		while (head->next)
			head = head->next;
	}
	if (!head)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		head->next = new_node;
		new_node->prev = head;
	}
}


#include "monty.h"
/**
 * _push - add a new node
 *
 * @stack: double linked list
 * @line_number: integer to add
 * Return: Nothing
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *newnode = NULL;

	if (stack)
	{
		newnode = malloc(sizeof(stack_t));
		if (!newnode)
		{
			free(newnode);
			return;
		}
		tmp = *stack;
		newnode->prev = NULL;
		newnode->next = tmp;
		newnode->n = line_number;
		if (newnode->next)
		{
			tmp->prev = newnode;
		}
		*stack = newnode;
	}
}

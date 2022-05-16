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
		newnode = (stack_t *)malloc(sizeof(stack_t));
		if (newnode == NULL)
		{
			free(newnode);
			return;
		}
		tmp = *stack;
		newnode->n = line_number;
		newnode->prev = NULL;
		newnode->next = tmp;
		if (newnode->next)
		{
			tmp->prev = newnode;
		}
		*stack = newnode;
	}

}

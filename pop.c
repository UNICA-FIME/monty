#include "monty.h"

/**
 * pop - delete the value at the top of a double linked list
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	temp = *stack;
	if (temp->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(temp);
	temp = NULL;
}

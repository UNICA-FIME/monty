#include "monty.h"

/**
 * pint - print the value at the top of a double linked list
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}

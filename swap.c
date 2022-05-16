#include "monty.h"

/**
 * swap - swap the first tow values at the top of a double linked list
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	size_t len = 0;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

/**
 * stack_len - calculate a size of a double linked list
 *
 * @h: double linked list
 * Return: size of h
 */

size_t stack_len(const stack_t *h)
{
	size_t size = 0;

	while (h)
	{
		h = h->next;
		size++;
	}
	return (size);
}

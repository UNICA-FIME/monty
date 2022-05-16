#include "monty.h"
/**
* pall - print a double linked list
*
* @stack: double linked list
* @line_number: Number to add (not used)
* Return: Nothing
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_dlistint(*stack);
}

/**
* print_dlistint - print a double linked list
*
* @h: double linked list
* Return: size of h
*/
size_t print_dlistint(const stack_t *h)
{
	size_t i = 0;

	if (h != NULL)
	{
		while (h != NULL)
		{
			printf("%d\n", h->n);
			i++;
			h = h->next;
															}
	}
	return (i);
}

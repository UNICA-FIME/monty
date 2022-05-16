#include "monty.h"
/**
* free_stack - free double linked list
*
* @head: double linked list
* Return: nothing
*/
void free_stack(stack_t *head)
{
	stack_t *current = NULL, *next_node = NULL;

	current = head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

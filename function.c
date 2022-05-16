#include "monty.h"
/**
 * run_code - function that choose the function to execute it
 *
 * @stack: linked list
 * @name: name of the function in the file
 * @value: number in he file
 * @line_number: number of the line in the file
 *
 * Return: nothing
 */

void run_code(stack_t **stack, char *name, char *value, int line_number)
{
	int i = 0;

	for (; array_fuction[i].opcode; i++)
	{
		if (strcmp(name, array_fuction[i].opcode) == 0)
		{
			if (strcmp(name, array_fuction[0].opcode) != 0)
			{
				array_fuction[i].f(stack, line_number);
				return;
			}
			if (strcmp(name, array_fuction[0].opcode) == 0 && !number_is(value))
			{
				status = EXIT_FAILURE;
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				return;
			}
			if (strcmp(name, array_fuction[0].opcode) == 0 && !value)
			{
				status = EXIT_FAILURE;
				fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
				return;
			}
			array_fuction[i].f(stack, atoi(value));
			return;
		}
	}
	status = EXIT_FAILURE;
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, name);
}

/**
* number_is - checks if a string is a number
* @str: provided string
*
* Return: 1 if the string is a number, else, 0.
*/

int number_is(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[i] == '-')
	{
		i++;
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

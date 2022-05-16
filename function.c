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
	int e = 0;

	for (; array_fuction[e].opcode; e++)
	{
		if (strcmp(name, array_fuction[e].opcode) == 0)
		{
			if (strcmp(name, array_fuction[0].opcode) != 0)
			{
				array_fuction[e].f(stack, line_number);
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
			array_fuction[e].f(stack, atoi(value));
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
	int f = 0;

	if (str == NULL)
		return (0);
	if (str[f] == '-')
	{
		f++;
	}
	for (; str[f] != '\0'; f++)
	{
		if (str[f] < '0' || str[f] > '9')
		{
			return (0);
		}
	}
	return (1);
}

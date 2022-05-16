#include "monty.h"

int status = 0;

/**
 * main - main function
 *
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int i = 0;
	size_t len  = 0;
	char *line = NULL, *token_name = NULL, *token_value = NULL;
	stack_t *st_1 = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = open_file(argv[1]);
	while (getline(&line, &len, file) != -1)
	{
		token_name = strtok(line, " \t\n");
		if (!token_name || *token_name == '#')
		{
			i++;
			continue;
		}
		token_value = strtok(NULL, " \t\n");
		run_code(&st_1, token_name, token_value, i + 1);
		if (status == EXIT_FAILURE)
		{
			free(line);
			free_stack(st_1);
			fclose(file);
			exit(status);
		}
		i++;

	}
	free(line);
	fclose(file);
	free_stack(st_1);
	return (0);
}

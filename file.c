#include "monty.h"
/**
 * _open - open a file
 *
 * @argv: file
 * Return: open file
 */
FILE *open_file(char *argv)
{
	FILE *fp;

	fp = fopen(argv, "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv);
		exit(EXIT_FAILURE);
	}
	return (fp);
}

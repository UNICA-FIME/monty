#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <stddef.h>


extern int status;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _push(stack_t **stack, unsigned int line_number);
void run_code(stack_t **stack, char *name, char *value, int line_number);
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
size_t print_dlistint(const stack_t *h);
void free_stack(stack_t *head);
/** Array of struct*/

static const instruction_t array_fuction[] = {
	{"push", _push},
	{"pall", pall},
	{NULL, NULL}};

/*Prototipo*/
int number_is(char *str);
FILE *open_file(char *argv);
#endif
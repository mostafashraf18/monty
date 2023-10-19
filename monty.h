#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct carry_s - carries values through the program
 * @arg: value
 * @file: pointer to monty file
 * @matrial: line content
 * @ch_fl: flag change stack to queue
 */
typedef struct carry_s
{
	char *arg;
	FILE *file;
	char *matrial;
	int ch_fl;
}  carry_t;
extern carry_t carry;

char *_realloc(char *ptr, unsigned int old_s, unsigned int new_s);
ssize_t getstdin(char **l_ptr, int file);
char  *clean_line(char *matrial);
void _push(stack_t **h_ptr, unsigned int num);
void _pall(stack_t **h_ptr, unsigned int num);
void _pint(stack_t **h_ptr, unsigned int num);
int execute(char *matrial, stack_t **h_ptr, unsigned int num, FILE *file);
void stack_free(stack_t *h_ptr);
void _pop(stack_t **h_ptr, unsigned int num);
void _swap(stack_t **h_ptr, unsigned int num);
void _add(stack_t **h_ptr, unsigned int num);
void _nop(stack_t **h_ptr, unsigned int num);
void _sub(stack_t **h_ptr, unsigned int num);
void _div(stack_t **h_ptr, unsigned int num);
void _mul(stack_t **h_ptr, unsigned int num);
void _mod(stack_t **h_ptr, unsigned int num);
void _pchar(stack_t **h_ptr, unsigned int num);
void _pstr(stack_t **h_ptr, unsigned int num);
void _rotl(stack_t **h_ptr, unsigned int num);
void _rotr(stack_t **h_ptr, __attribute__((unused)) unsigned int num);
void node_add(stack_t **h_ptr, int n);
void queue_add(stack_t **h_ptr, int n);
void _queue(stack_t **h_ptr, unsigned int num);
void _stack(stack_t **h_ptr, unsigned int num);

#endif

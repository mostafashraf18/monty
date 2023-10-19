#include "monty.h"

/**
 * _stack -  sets the format of the data to a stack (LIFO)
 * @h_ptr: stack head pointer
 * @num: intiger line counter
 * Return: void
 */
void _stack(stack_t **h_ptr, unsigned int num)
{
	(void)h_ptr;
	(void)num;
	carry.ch_fl = 0;
}

/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @h_ptr: stack head pointer
 * @num: intiger line counter
 * Return: void
 */
void _queue(stack_t **h_ptr, unsigned int num)
{
	(void)h_ptr;
	(void)num;
	carry.ch_fl = 1;
}

/**
 * stack_free - frees a doubly linked list
 * @h_ptr: head of the stack
 * Return: void
 */
void stack_free(stack_t *h_ptr)
{
	stack_t *a;

	a = h_ptr;
	while (h_ptr)
	{
		a = h_ptr->next;
		free(h_ptr);
		h_ptr = a;
	}
}


/**
 * queue_add - add node to the end of stack
 * @n: new value
 * @h_ptr: stack head pointer
 * Return: void
 */
void queue_add(stack_t **h_ptr, int n)
{
	stack_t *new_n, *a;

	a = *h_ptr;
	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{
		printf("Error\n");
	}
	new_n->n = n;
	new_n->next = NULL;
	if (a)
	{
		while (a->next)
			a = a->next;
	}
	if (!a)
	{
		*h_ptr = new_n;
		new_n->prev = NULL;
	}
	else
	{
		a->next = new_n;
		new_n->prev = a;
	}
}



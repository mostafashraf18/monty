#include "monty.h"

/**
 * node_add - add node to the head stack
 * @h_ptr: head stack pointer
 * @n: intiger new value
 * Return: void
 */
void node_add(stack_t **h_ptr, int n)
{

	stack_t *new_n, *a;

	a = *h_ptr;
	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{ printf("Error\n");
		exit(0); }
	if (a)
		a->prev = new_n;
	new_n->n = n;
	new_n->next = *h_ptr;
	new_n->prev = NULL;
	*h_ptr = new_n;
}

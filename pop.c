#include "monty.h"

/**
 * _pop - remove the top element of the stack
 * @h_ptr: stack head pointer
 * @num: intigerline number
 * Return: void
 */
void _pop(stack_t **h_ptr, unsigned int num)
{
	stack_t *h;

	if (*h_ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*h_ptr);
		exit(EXIT_FAILURE);
	}
	h = *h_ptr;
	*h_ptr = h->next;
	free(h);
}


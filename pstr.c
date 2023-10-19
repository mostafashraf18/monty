#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * followed by a new line
 * @h_ptr: stack head pointer
 * @num: intiger line counter
 * Return: void
 */
void _pstr(stack_t **h_ptr, unsigned int num)
{
	stack_t *h;
	(void)num;

	h = *h_ptr;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

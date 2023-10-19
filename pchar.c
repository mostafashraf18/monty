#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @h_ptr: stack head pointer
 * @num: intiger line number
 * Return: void
 */
void _pchar(stack_t **h_ptr, unsigned int num)
{
	stack_t *h;

	h = *h_ptr;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*h_ptr);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*h_ptr);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

#include "monty.h"

/**
 * _pint - prints the top of the stack followed by new line
 * @h_ptr: stack head pointer
 * @num: intiger line number
 * Return: void
 */
void _pint(stack_t **h_ptr, unsigned int num)
{
	if (*h_ptr == NULL)
	{
		/*to wright data in a file using stream object not stdout console*/
		fprintf(stderr, "L%u: can't pint, stack empty\n", num);
		/*deleyes all buffers that are acssociated with the stream before closing*/
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*h_ptr);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h_ptr)->n);
}

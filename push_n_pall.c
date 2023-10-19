#include "monty.h"

/**
 * _push - add element to the stack
 * @h_ptr: stack head pointer
 * @num: intiger line counter
 * Return: void
 */
void _push(stack_t **h_ptr, unsigned int num)
{
	int n, i = 0, z = 0;

	if (carry,arg)
	{
		if (carry.arg[0] == '-')
			i++;
		for (; carry.arg[i] != '\0'; i++)
		{
			if (carry.arg[i] > 57 || carry.arg[i] < 48)
				z = 1;
		}
		if (z == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num);
			/*deletes all buffers that are acssociated with the stream*/
			fclose(carry.file);
			free(carry.matrial);
			stack_free(*h_ptr);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*to wright data in a file using stream object not stdout console*/
		fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*h_ptr);
		exit(EXIT_FAILURE);
	}
	n = atoi(carry.arg);
	if (carry.ch_fl == 0)
		node_add(h_ptr, n);
	else
		queue_add(h_ptr, n);
}

/**
 * _pall - prints all the values on the stack
 * @h_ptr: stack head pointer
 * @num: intuger
 * Return: void
 */
void _pall(stack_t **h_ptr, unsigned int num)
{
	stack_t *h;
	(void)num;

	h = *h_ptr;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

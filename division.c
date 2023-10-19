#include "monty.h"
/**
 * _div - divides the top two elements
 * @head:  head
 * @counter: line number
*/
void _div(stack_t **head, unsigned int counter)
{
	stack_t *temp_head;
	int size = 0, aux;

	temp_head = *head;
	while (temp_head)
	{
		temp_head = temp_head->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	temp_head = *head;
	if (temp_head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	aux = temp_head->next->n / temp_head->n;
	temp_head->next->n = aux;
	*head = temp_head->next;
	free(temp_head);
}

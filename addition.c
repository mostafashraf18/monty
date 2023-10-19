#include "monty.h"
/**
 * _add - adds the top two elements of the stack
 * @head: head
 * @counter: line number
*/
void _add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	temp_head = *head;
	aux = temp_head->n + temp_head->next->n;
	temp_head->next->n = aux;
	*head = temp_head->next;
	free(temp_head);
}

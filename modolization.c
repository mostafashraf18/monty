#include "monty.h"
/**
 * _mod - computes the  mod of the first two elements
 * @head: stack head
 * @counter: linenumber
*/
void _mod(stack_t **head, unsigned int counter)
{
	stack_t *head_temp;
	int size = 0, aux;

	head_temp = *head;
	while (head_temp)
	{
		head_temp = head_temp->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	head_temp = *head;
	if (head_temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(carry.file);
		free(carry.matrial);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	aux = head_temp->next->n % head_temp->n;
	head_temp->next->n = aux;
	*head = head_temp->next;
	free(head_temp);
}

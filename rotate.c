#include "monty.h"
/**
  *_rotr- rotates the stack to bottom
  *@head: head
  *@counter: line number
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}

/**
  *_rotl- rotates the stack top
  *@head: head
  *@counter: linen number
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *head, *nxt;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	nxt = (*head)->next;
	nxt->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = nxt;
}

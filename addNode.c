#include "monty.h"

/**
 * add_node - Adds a new node at the beginning of a doubly-linked list.
 * @stack: A pointer to the head of the doubly-linked list.
 * @data: The data to be stored in the new node.
 */
void add_node(stack_t **stack, int data)
{
	stack_t *temp, *new_node;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(0);
	}

	if (*stack)
		(*stack)->prev = new_node;
	new_node->n = data;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

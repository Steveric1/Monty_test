#include "monty.h"

/**
 * pushFunc - Pushes an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number where the instruction appears.
 */
void pushFunc(stack_t **stack, unsigned int line_number)
{
    char *value = strtok(NULL, " \t\n");

    if (value == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int n = atoi(value);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * pallFunc - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the stack.
 * @line_number: The line number where the instruction appears.
 */
void pallFunc(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number; // Unused parameter, avoid a warning

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void freeStack(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        stack_t *temp = current;
        current = current->next;
        free(temp);
    }
    *stack = NULL;
}

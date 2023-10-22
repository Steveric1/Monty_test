#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct stream - A structure to represent a stream with a FILE pointer.
 * @file: A pointer to a FILE object associated with the stream.
 */
typedef struct stream
{
	FILE *file;
} stream_t;
extern stream_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void processMonty(stream_t file);
void pushFunc(stack_t **stack, unsigned int line_number);
void pallFunc(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, int data);
void freeStack(stack_t **stack);
void processInstruction(char *line, unsigned int line_number, stack_t **stack);
void pintFunc(stack_t **stack, unsigned int line_number);
void popFunc(stack_t **stack, unsigned int line_number);

#endif /*_MONTY_H_*/

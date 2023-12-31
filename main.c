#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - add int to stack as header
 * @stack: stack linked list
 * @line_number: number to insert on stack
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value = line_number;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all stack elements
 * @stack: stack linked list
 * @line_number: number to insert on stack
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	unsigned int i = 0;

<<<<<<< HEAD
	while (current != NULL && i <= line_number)
	{
		printf("%d\n", current->n);
		current = current->next;
		i++;
	}
=======
   if (argc == 2)
	   pFile = fopen (argv[1] , "r");
   if (pFile == NULL) perror ("Error opening file");
   else
   {
     while ( !feof (pFile) )
     {
	line_number++;
       if ( fgets (buffer , 100 , pFile) == NULL ) break;
       fun = strtok(buffer, " \n");
	
       if (strcmp(fun, "push") == 0)
	       push(&stack, line_number);
       if (strcmp(fun, "pall") == 0)
	       pall(&stack);	
     }
     fclose (pFile);
   }
   return 0;
>>>>>>> parent of b9f44bc... Update main.c
}
/**
 * main- executes command from argument
 * @argc: number of command
 * @argv: operation and command file
 * Return: 0 on success
 *
 */

int main(int argc, char *argv[])
{
	FILE *pFile;
	char buffer[100];
	stack_t *stack = NULL;
	/*char *opcode = NULL;	*/
	unsigned int line_number = 0;
	char *fun;

	if (argc == 2)
		pFile = fopen(argv[1], "r");
	if (pFile == NULL)
		perror("Error opening file");
	else
	{
		while (!feof(pFile))
		{
			line_number++;
			if (fgets(buffer, 100, pFile) == NULL)
				break;
			fun = strtok(buffer, " \n");

			if (strcmp(fun, "push") == 0;
				push(&stack, line_number);
			if (strcmp(fun, "pall") == 0;
				pall(&stack);
		}
		fclose(pFile);
	}
	return (0);
}

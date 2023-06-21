#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void pall(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
   FILE * pFile;
   char buffer [100];
   stack_t *stack = NULL;
   /*char *opcode = NULL;	*/
   unsigned int line_number = 0;
   char *fun;
   
   

   if (argc == 2)
	   pFile = fopen (argv[1] , "r");
  else
	  printf("USAGE: monty file");
	  exit(EXIT_FAILURE);
	   
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
}

/*int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    char *opcode = NULL;
    size_t line_size = 1000;
    unsigned int line_number = 0;
    while (getline(&opcode, &line_size, argv[1]) != -1)
    {
        line_number++;
        instruction_t *instruction = argv[0];
        if (instruction == NULL)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
        instruction->f(&stack, line_number);
    }

    free(stack);

    return 0;
}*/

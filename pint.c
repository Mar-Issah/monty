
#include "monty.h"
/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

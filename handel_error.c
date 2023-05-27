#include "monty.h"
/**
 * handle_error - handle error

 */
void handle_error()
{
	free(global.buffer);
	fclose(global.file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
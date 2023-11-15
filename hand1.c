#include "main.h"

/**
  * d_hand - Handles the signals
  * @ante_id: The identifier of the signal to handle
  *
  * Return: Nothing 
  */
void d_hand(int ante_id)
{
	if (ante_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}

#include "main.h"

/**
 * free_value - frees data structure
 *
 * @storesh: data structure
 * Return: no return
 */




void free_value(store_shell *storesh)
{
	unsigned int d;

	for (d = 0; storesh->_work[d]; d++)
	{
		free(storesh->_work[i]);
	}

	free(storesh->_work);
	free(storesh->pid);
}

/**
 * set_value - Initialize data structure
 *
 * @storesh: data structure
 * @da: argument vector
 * Return: no return
 */
void set_value(store_shell *storesh, char **da)
{
	unsigned int d;

	storesh->da = da;
	storesh->input = NULL;
	storesh->args = NULL;
	storesh->counter = 1;
	storesh->status = 0;

	for (d = 0; environ[d]; d++)
		;

	storesh->_work = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		storesh->_work[i] = _strdup(environ[i]);
	}

	storesh->_work[i] = NULL;
	storesh->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @dd: argument count
 * @da: argument vector
 *
 * Return: 0 on success.
 */
int main(int dd, char **da)
{
	store_shell storesh;
	(void) dd;

	signal(SIGINT, get_sigint);
	set_data(&storesh, da);
	shell_loop(&storesh);
	free_data(&storesh);
	if (storesh.status < 0)
		return (255);
	return (storesh.status);
}

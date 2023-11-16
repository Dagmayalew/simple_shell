#include "main.h"
/**
 * releaseResources - Deallocates memory and resources
 *
 * @dataContainer: Pointer to the data container structure.
 * Return: No return value.
 */
void releaseResources(data_container *dataContainer)
{
	unsigned int index;

	for (index = 0; dataContainer->_environment[index]; index++)
	{sa
		free(dataContainer->_environment[index]);
	}

	free(dataContainer->_environment);
	free(dataContainer->processId);
}

/**
 * initializeData - Initialize data structure
 *
 * @dataContainer: data structure
 * @arguments: argument vector
 * Return: no return
 */
void initializeData(data_container *dataContainer, char **arguments)
{
	unsigned int index;

	dataContainer->argVector = arguments;
	dataContainer->input = NULL;
	dataContainer->arguments = NULL;
	dataContainer->status = 0;
	dataContainer->counter = 1;

	for (index = 0; environ[index]; index++)
		;

	dataContainer->_environment = malloc(sizeof(char *) * (index + 1));

	for (index = 0; environ[index]; index++)
	{
		dataContainer->_environment[index] = _strdup(environ[index]);
	}

	dataContainer->_environment[index] = NULL;
	dataContainer->processId = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @argumentCount: argument count
 * @argumentVector: argument vector
 *
 * Return: 0 on success.
 */
int main(int argumentCount, char **argumentVector)
{
	data_container dataContainer;
	(void) argumentCount;

	signal(SIGINT, handleSigint);
	initializeData(&dataContainer, argumentVector);
	shellLoop(&dataContainer);
	releaseResources(&dataContainer);
	if (dataContainer.status < 0)
		return (255);
	return (dataContainer.status);
}

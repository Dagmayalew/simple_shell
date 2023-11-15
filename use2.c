#include "main.h"

/**
 * out - writes the character c to stdout
 * @d: The character to print
 *
 * Return: success 1.
 * error, -1 is returned
 */
int out(char d)
{
	return (write(1, &d, 1));
}


/**
  * p_string - Prints a string
  * @tsi: The string to print
  *
  * Return: no returns
  */
void p_string(char *tsi)
{
	while (*tsi)
	{
		out(*tsi);
		tsi++;
	}

	out('\n');
}

/**
  * compTwoString - Compares first string and second string
  * @tom: The first string
  * @hlu: The second string
  * @length: The limit bytes of comparison
  *
  * Return: int value
  */
int compTwoString(const char *tom, const char *hlu, size_t length)
{
	unsigned int ale = 0;
	int lyu = 0;

	while (ale < length)
	{
		if (tom[ale] == hlu[ale])
		{
			ale++;
			continue;
		}
		else
		{
			lyu = tom[ale] - hlu[ale];
			break;
		}

		ale++;
	}

	return (lyu);
}

/**
  * anotherSize - Resize the tek that was previously allocated
  * @tek: The pointer previously allocated
  * @arg: The old size of the pointer
  * @adi: The new size of the new pointer
  *
  * Return: New pointer
  */
void *anotherSize(void *tek, unsigned int arg, unsigned int adi)
{
	char *dek;
	unsigned int i;

	if (adi == arg)
		return (tek);

	if (tek == NULL)
	{
		dek = malloc(adi);

		if (dek == NULL)
			return (NULL);

		return (dek);
	}
	else
	{
		if (adi == 0)
		{
			free(tek);
			return (NULL);
		}
	}

	dek = malloc(adi);

	if (dek == NULL)
		return (NULL);

	for (i = 0; i < arg && i < adi; i++)
	{
		dek[i] = ((char *) tek)[i];
	}

	free(tek);
	return (dek);
}

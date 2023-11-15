#include "main.h"

/**
  * kot_in - Counts the words typed by the user
  * @lis: The string that contains the words
  *
  * Return: The number of words found in the string
  */
int kot_in(char *lis)
{
	int d = 0, fst = 0, cit = 0;

	while (lis[d])
	{
		if (lis[d] == ' ' || lis[d] == '\n' || lis[d] == '\t')
			cit = 0;
		else if (cit == 0)
		{
			cit = 1;
			fst++;
		}

		d++;
	}

	return (fst);
}

/**
  * kot_del - Counts delimiters in a string
  * @lis: The string that contains the delimiters
  * @dst: The delimiters to will find in the string
  *
  * Return: The number of delimiters in the string
  */
int kot_del(char *lis, char *dst)
{
	int d = 0, e = 0, fst = 0;

	while (dst[d])
	{
		e = 0;
		while (lis[e])
		{
			if (lis[e] == dst[d])
				fst++;
			e++;
		}
		e++;
	}

	return (fst);
}

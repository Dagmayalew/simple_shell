#include "main.h"

/**
  * _concat2 - Concatenates two strings
  * @dag: The destination string
  * @eyu: The source string
  *
  * Return: A pointer to the resulting string dest
  */
char *_concat2(char *dag, char *eyu)
{
	int length = 0, d = 0;

	while (dag[length])
		length++;

	for (d = 0; eyu[d] != '\0'; d++)
	{
		dag[length] = eyu[d];
		length++;
	}

	dag[length] = '\0';
	return (dag);
}

/**
  * _stringLength - Counts the length of a string
  * @d: The string to counts
  *
  * Return: The length of a string
  */
int _stringLength(const char *d)
{
	int e = 0;

	while (d[e])
		e++;

	return (e);
}

/**
  * _compareStrings - Compares two strings
  * @tom: The first string
  * @hlu: The second string
  *
  * Return: int value
  */
int _compareStrings(char *tom, char *hlu)
{
	int tom1 = 0;
	int tom2 = 0;
	int ela = 0;
	int lyu = 0;
	int gud = 0;

	tom1 = _stringLength(tom);
	tom2 = _stringLength(hlu);

	if (tom1 <= tom2)
		gud = tom1;
	else
		gud = tom2;

	while (ela <= gud)
	{
		if (tom[ela] == hlu[ela])
		{
			ela++;
			continue;
		}
		else
		{
			lyu = tom[ela] - hlu[ela];
			break;
		}

		ela++;
	}

	return (lyu);
}

/**
  * _duplicateString - Duplicate a string
  * @mik: the string to duplicate
  *
  * Return: the string duplicated
  */
char *_duplicateString(char *mik)
{
	int mes = 0, length = 1;
	char *duplicate;

	if (mik == NULL)
		return (NULL);

	length = _stringLength(mik);
	duplicate = malloc((sizeof(char) * length) + 1);
	if (duplicate == NULL)
		return (NULL);

	while (mes < length)
	{
		duplicate[mes] = mik[mes];
		mes++;
	}

	duplicate[mes] = '\0';
	return (duplicate);
}

/**
  * _convertString - Convert a string to an integer.
  * @d: The pointer to convert
  *
  * Return: A integer
  */
int _convertString(char *d)
{
	int nah = 1, tsi = 0, ale = 0;
	unsigned int hen = 0;

	while (d[ale])
	{
		if (d[ale] == '-')
			nah *= -1;

		while (d[ale] >= '0' && d[ale] <= '9')
		{
			tsi = 1;
			hen = (hen * 10) + (d[ale] - '0');
			ale++;
		}

		if (tsi == 1)
			break;

		ale++;
	}

	hen *= nah;
	return (hen);
}


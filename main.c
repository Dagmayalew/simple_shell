#include "main.h"

/**
  * main - Entry point to the Shell
  *
  * Return: Always zero.
  */
int main(void)
{
	char *mes = NULL, **tek = NULL;
	int dlen = 0, band = 0;
	size_t mes_si = 0;
	ssize_t mes_le = 0;

	while (mes_le >= 0)
	{
		signal(SIGINT, ante_hand);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		mes_le = getline(&mes, &mes_si, stdin);
		if (mes_le == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		dlen = con(mes);
		if (line[0] != '\n' && dlen > 0)
		{
			tek = coin(mes, " \t", dlen);
			band = bu_com(tek, mes);
			if (!band)
			{
				tek[0] = fel(tek[0]);
				if (tek[0] && access(tek[0], X_OK) == 0)
					uni(tek[0], tek);
				else
					perror("./hsh");
			}

			f_coin(tek);
		}
	}

	free(mes);
	return (0);
}

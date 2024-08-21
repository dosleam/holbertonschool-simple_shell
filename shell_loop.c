#include "main.h"

/**
 * shell_loop - Boucle principale du shell
 * Description: Gère l'entrée de l'utilisateur et exécute les commandes
 * Return: Rien
 */

void shell_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	char **args;

	while (1)
	{
		printf("Ready $ ");
		if (getline(&line, &len, stdin) == -1)
		{
			break;
		}
		args = parse_command(line);
		if (args[0])
		{
			handle_command(args);
		}
		free(args);
		}
		free(line);
}

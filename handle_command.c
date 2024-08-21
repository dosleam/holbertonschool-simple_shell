#include "main.h"

/**
 * handle_command - Gère l'exécution d'une commande
 * @args: Tableau d'arguments de la commande
 *
 * Description: Exécute des commandes internes (comme `exit` et `cd`),
 * ou passe les commandes externes à `execute_command`.
 * Return: Rien
 */

void handle_command(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(0);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		if (args[1])
		{
			chdir(args[1]);
		}
	}
	else if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else
	{
		execute_command(args);
	}
}

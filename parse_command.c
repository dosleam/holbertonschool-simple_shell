#include "main.h"

/**
 * parse_command - Analyse une ligne de commande en arguments
 * @line: Ligne de commande saisie par l'utilisateur
 *
 * Description: Sépare la ligne de commande en arguments
 * séparés par des espaces et les stocke dans un tableau.
 * Return: Un tableau d'arguments, ou NULL en cas d'erreur.
 */

char **parse_command(char *line)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *token;
	int i = 0;

	if (!args)
	{
		return (NULL);
	}
	token = strtok(line, " \t\r\n\a");
	while (token && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\r\n\a");
	}
	args[i] = NULL;
	return (args);
}

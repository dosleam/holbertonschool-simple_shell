#include "main.h"

/**
 * build_path - Construit un chemin complet pour une commande
 * @path: Chemin de base (repertoire)
 * @cmd: Nom de la commande
 *
 * Description: Combine le chemin de base et le nom de la commande
 * pour creer un chemin complet vers l'executable.
 * Return: Un pointeur vers le chemin complet, ou NULL en cas d'erreur.
 */

char *build_path(char *path, char *cmd)
{
	char *full_path;

	full_path = malloc(strlen(path) + strlen(cmd) + 2);

	if (full_path == NULL)
	{
		return (NULL);
	}

	if (full_path)
	{
		sprintf(full_path, "%s/%s", path, cmd);
	}
	return (full_path);
}

/**
 * get_command_path - Trouve le chemin d'une commande
 * @command_name: Nom de la commande Ã  chercher
 *
 * Description: Parcourt les chemins definis dans la variable d'environnement
 * PATH pour trouver oÃ¹ se trouve la commande.
 * Return: Le chemin complet vers la commande, ou NULL si introuvable.
 */

char *get_command_path(char *command_name)
{
	char *path_env;
	char *path;
	char *full_path;

	if (access(command_name, X_OK) == 0)
	{
		return (strdup(command_name));
	}
	path_env = strdup(getenv("PATH"));
	if (path_env == NULL)
	{
		return (NULL);
	}
	path = strtok(path_env, ":");
	while (path)
	{
		full_path = build_path(path, command_name);
		if (full_path == NULL)
		{
			free(path_env);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(path_env);
			return (full_path);
		}
		free(full_path);
		path = strtok(NULL, ":");
	}
	free(path_env);
	return (NULL);
}

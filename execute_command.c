#include "main.h"

/**
 * execute_command - Fork un processus et exÃ©cute une commande
 * @args: Tableau d'arguments pour la commande
 *
 * Description: CrÃ©e un processus enfant pour exÃ©cuter la commande.
 * Le parent attend que l'enfant termine.
 * Return: Rien
 */

void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		exec_command(args);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
	}
}

/**
 * exec_command - ExÃ©cute une commande en utilisant execve
 * @args: Tableau d'arguments pour la commande
 *
 * Description: Trouve le chemin de la commande et l'exÃ©cute
 * en remplaÃ§ant le processus courant par le nouveau.
 * Return: Rien
 */

void exec_command(char **args)
{
	char *command_path;

	command_path = get_command_path(args[0]);

	if (command_path)
	{
		execve(command_path, args, environ);
	}
	else
	{
		printf("command not found: %s\n", args[0]);
	}
	perror("execve");
	exit(EXIT_FAILURE);
}

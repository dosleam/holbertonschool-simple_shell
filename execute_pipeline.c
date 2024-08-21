#include "main.h"

/**
 * run_child - Execute le processus enfant
 * @fd_in: Descripteur de fichier pour l'entree standard
 * @fd: Tableau de descripteurs de fichiers pour le pipe
 * @args: Tableau d'arguments de la commande
 * @next_command: Indique si une commande suivante existe
 *
 * Description: Configure les descripteurs de fichiers et execute la commande
 * dans le processus enfant.
 * Return: Rien
 */
void run_child(int fd_in, int fd[2], char **args, int next_command)
{
	char *command_path;

	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (next_command && dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);

	command_path = get_command_path(args[0]);

	if (command_path)
	{
		execve(command_path, args, environ);
	}
	perror("execve");
	exit(EXIT_FAILURE);
}

/**
 * execute_pipeline - Execute une serie de commandes en pipeline
 * @commands: Tableau de commandes a  executer
 * Description: Gere l'execution de plusieurs commandes
 * en utilisant des pipes.
 * Return: Rien
 */

void execute_pipeline(char **commands)
{
	int fd[2];
	int fd_in = 0;
	pid_t pid;
	char **args;

	while (*commands)
	{
		args = parse_command(*commands);

		if (pipe(fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) /* Processus enfant */
		{
			run_child(fd_in, fd, args, *(commands + 1) != NULL);
		}
		else /* Processus parent */
		{
			wait(NULL);
			close(fd[1]);
			fd_in = fd[0];
			commands++;
		}
	}
}

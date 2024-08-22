#include "main.h"

/**
 * generate_temp_filename - Génère un nom de fichier temporaire unique
 * @index: Indice pour différencier les fichiers temporaires
 * @buffer: Buffer pour stocker le nom de fichier généré
 * Description: Utilise l'indice pour générer un nom
 * de fichier temporaire unique.
 * Return: Rien
 */
void generate_temp_filename(int index, char *buffer)
{
	sprintf(buffer, "temp%d.tmp", index);
}

/**
 * run_child - Execute le processus enfant
 * @fd_in: Descripteur de fichier pour l'entree standard
 * @fd_out: Descripteur de fichier pour la sortie standard
 * @args: Tableau d'arguments de la commande
 *
 * Description: Configure les descripteurs de fichiers et execute la commande
 * dans le processus enfant.
 * Return: Rien
 */
void run_child(int fd_in, int fd_out, char **args)
{
	if (fd_in != STDIN_FILENO)
	{
		close(STDIN_FILENO);
		open("/dev/null", O_RDONLY);
	}

	if (fd_out != STDOUT_FILENO)
	{
		close(STDOUT_FILENO);
		open("/dev/null", O_WRONLY);
	}

	execve(args[0], args, environ);
	perror("execve");
	exit(EXIT_FAILURE);
}

/**
 * execute_pipeline - Execute une serie de commandes en pipeline
 * @commands: Tableau de commandes à exécuter
 * Description: Gère l'exécution de plusieurs commandes
 * en utilisant des fichiers temporaires.
 * Return: Rien
 */
void execute_pipeline(char **commands)
{
	int fd_in = STDIN_FILENO;
	int fd_out;
	pid_t pid;
	char **args;
	char temp_file[20];
	int file_index = 0;

	while (*commands)
	{
		generate_temp_filename(file_index++, temp_file);
		fd_out = open(temp_file, O_CREAT | O_WRONLY | O_TRUNC, 0600);
		if (fd_out == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		args = parse_command(*commands);
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			run_child(fd_in, fd_out, args);
		}
		else
		{
			wait(NULL);
			close(fd_out);
			fd_in = open(temp_file, O_RDONLY);
			if (fd_in == -1)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
			commands++;
		}
	}
}

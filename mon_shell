#include "main.h"

int main(int argc __attribute__((unused)),
	char **argv __attribute__((unused)), char **envp)
{
	char *line = NULL, *env[64];
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, i = 0, result_print_env;
	char **args;

	args = malloc(i * sizeof(char *));
	while (1)/* affiche #cisfun en attendant une commande*/
	{
		/* probleme d'allocation*/		
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		i = 0;
		line = NULL;
		len = 0;
		read = getline(&line, &len, stdin);

		if (read != -1) /*lit le flux*/
		{
			_strtok(args, line);
			fonction_de_sortie(args[0]);
			result_print_env = print_env(args[0], envp);
			cut_path(env);

			if (result_print_env == 1)
			{
				child_pid = fork();/*crée process*/
				/* free parent ? */
				if (child_pid < 0)
					exit(100);

				if (child_pid == 0)
				{
					if (execve(args[0], args, env) == -1)/*execute*/
					{
						perror("./shell");
						exit(1);
					}
				}
			}
			wait(&status);
		}
		free(line);
		line = NULL;
		len = 0;

	}
	free_array(args);
	return (1);
}

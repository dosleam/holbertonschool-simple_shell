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
	/* probleme d'allocation*/
	while (1)/* affiche #cisfun en attendant une commande*/
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		i = 0;
		line = NULL;
		len = 0;
		read = getline(&line, &len, stdin);

		if (read != -1) /*lit le flux*/
		{
			_strtok(args, line);
			sortie_fonction(args[0]);
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
		free(args);
		line = NULL;
		len = 0;
	}
	return (0);
}

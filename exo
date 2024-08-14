
pid_t child_pid;
int status;
char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

for (i = 0; i < 5; i++)
{
    child_pid = fork();
    if (child_pid < 0)
    {
        exit(100);
    }
    if (child_pid == 0)
    {
        if (execve("/bin/ls", args, NULL) == -1)
        {
            perror("execve");
            exit(1);
        }
    } else
    {
        wait(&status);
    }
}
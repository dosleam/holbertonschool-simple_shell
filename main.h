#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

#define MAX_ARGS 64

void execute_command(char **args);
void exec_command(char **args);
char **parse_command(char *line);
void handle_command(char **args);
char *get_command_path(char *command_name);
void shell_loop(void);
void run_child(int fd_in, int fd_out, char **args);
char *build_path(char *path, char *cmd);
void execute_pipeline(char **commands);
void generate_temp_filename(int index, char *buffer);

#endif /* MAIN_H */

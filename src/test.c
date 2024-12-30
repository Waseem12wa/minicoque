#include "../include/minishell.h"

int main()
{
	char *line;
	int fd;
	fd = dup(0);
	line = readline("INPUT : ");
	printf("%s", line);
	close(0);
	dup2(fd, 0);
	line = readline("INPUT : ");
	printf("%s", line);
}
#include "../../include/minishell.h"

int	ft_append(char **args)
{
	int		fd;

	fd = -1;
	fd = open(args[1], O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		perror("file doesn't exist");
	if (dup2(fd, 1) == -1) 
		perror("dup2");
	return (fd);
}

int	ft_trunc(char **args)
{
	int		fd;

	fd = -1;
	fd = open(args[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		perror("file doesn't exist");
	if (dup2(fd, 1) == -1) 
		perror("dup2");
	return (fd);
}

int operator_choice(char **tab, int *fd)
{
	*fd = -1;
	if (!tab)
		return (-1);
	if (ft_strncmp(tab[0], ">>", 2) == 0)
			*fd = ft_append(tab);
	else if (ft_strncmp(tab[0], ">", 1) == 0)
			*fd = ft_trunc(tab);
	return (*fd);
}
#include "../../include/minishell.h"

bool exect_builtin(char **args, t_data *data)
{
	if (ft_strncmp(args[0], "echo", 4) == 0)
		echo_command(args);
	else if (ft_strncmp(args[0], "cd", 2) == 0)
		cd_command(args, data);
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
		pwd_command();
	else if (ft_strncmp(args[0], "export", 6) == 0)
		export_command(args, data);
	else if (ft_strncmp(args[0], "unset", 5) == 0)
		unset_command(args, data);
	else if (ft_strncmp(args[0], "env", 3) == 0)
		env_command(args, data);
	else if (ft_strncmp(args[0], "exit", 4) == 0)
		exit_command();
	return (FALSE);
}

bool exec_all(char **args, t_data *data)
{
	int code;
	
	code = 0;
	code = execve(data->path[data->nb_path], args, env_to_tab(data->env)); 
	exit(code);
}

bool ifbuiltin(char **args)
{
	if (ft_strncmp(args[0], "echo", 4) == 0)
		return (TRUE);
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(args[0], "cd", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(args[0], "export", 6) == 0)
		return (TRUE);
	else if (ft_strncmp(args[0], "unset", 5) == 0)
		return (TRUE);
	else if (ft_strncmp(args[0], "env", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(args[0], "exit", 4) == 0)
		return (TRUE);
	return (FALSE);
}

bool 	exec_pipe(t_data *data, char ***tab)
{
	pid_t	pid;
	int i;
	int status;
	int fd;
	
	tab = data->args;
	i = 0;

	while (tab[i])
	{
		if (pipe(data->pipe) == -1)
			perror("PIPE !");
		pid = fork();
		if (pid == -1)
			perror("fork");
		if (pid == 0)
		{
			if (tab[i + 1] && operator_choice(tab[i + 1], &fd) == -1)
			{
				change_pipe(data, data->pipe[0], data->pipe[1], 1);
			}
			if (ifbuiltin(tab[i]) == TRUE)
			{
				exect_builtin(tab[i], data);
				exit(0);
			}
			else
			{
				if (!exec_all(tab[i], data))
					return (FALSE);
			}
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exit_value = WEXITSTATUS(status);
		data->nb_path++;
		if (fd != -1)
		{
			data->nb_path++;
			i++;
			close(fd);
			dup2(data->fd_out, 1);
		}
		else
			change_pipe(data, data->pipe[0], data->pipe[1], 2);
		fd = -1;
		i++;
	}
	change_pipe(data, data->pipe[0], data->pipe[1], 3);
	return (TRUE);
}


bool	exec_cmd(t_data *data, char ***tab)
{
	pid_t	pid;
	int fd;
	int status;
	
	fd = -1;
	status = 0;
	fd = operator_choice(tab[1], &fd);
	if (ifbuiltin(tab[0]) == TRUE)
		exect_builtin(tab[0], data);
	else
	{
		pid = fork();
		if (pid == -1)
			perror("fork");
		if (pid == 0)
			exec_all(tab[0], data);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exit_value = WEXITSTATUS(status);	
	}
	if (fd != -1)
	{
		close(fd);
		dup2(data->fd_out, 1);
	}
  return (TRUE);
}

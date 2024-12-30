#include "../../include/minishell.h"

void  change_pipe(t_token *token, int fd_in, int fd_out)
{
		dup2(token->pipe[0], fd_in);
		dup2(token->pipe[1], fd_out);
}
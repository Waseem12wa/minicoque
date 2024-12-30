#include "../../include/minishell.h"

bool emptyline(char *line) 
{
  if (ft_strlen(line) == 0)
    return (FALSE);
  else
    return (TRUE);
}

bool spliting_cmd(char *line, t_data *data) 
{
  char **tab;
  int i;
  char **tab_temp;

  i = 0;
  tab = split_quote(line);
  tab_temp = split_sep(tab, "<|> ");
  data->cmd = NULL;
  if (!tab_temp)
    return (FALSE);
  while (tab_temp[i]) 
  {
    ft_lstadd_back(&(data->cmd), ft_lstnew(tab_temp[i]));
    i++;
  }
  return (TRUE);
}

bool replace_env_var(t_data *data) 
{
  t_token *token;
  int var;
  int i;

  token = data->token;
  i = 0;
  var = 0;
  while (token) 
  {
    if (var == 0)
      var = count_replace(token->str);
    if (token->sq != TRUE && is_exitcode(token->str) >= 0)
    {
      token->str = replace_exitcode(token->str);
      i++;
    }
    else if (token->sq != TRUE && is_pid(token->str) >= 0) 
    {
      token->str = replace_pid(token->str);
      i++;
    } else if (token->sq != TRUE && is_dollar(token->str) >= 0) 
    {
      token->str = replace_var(token->str, data);
      i++;
    }
    if (i == var || token->sq == TRUE) 
    {
      token = token->next;
      i = 0;
      var = 0;
    }
  }
  return (TRUE);
}

void count_pipe(char *line, t_data *data) 
{
  int i;

  i = 0;
  data->pipe_nbr = 0;
  data->id_pipe = 0;
  while (line[i]) 
  {
    if (line[i] == '|')
      data->pipe_nbr++;
    i++;
  }
}

bool parsing(char *line, t_data *data) 
{
  if (!quote_check(line))
    return (FALSE);
  if (!spliting_cmd(line, data))
    return (FALSE);
  if (!token_setup(data))
    return (FALSE);
  if (!replace_env_var(data))
    return (FALSE);
  count_pipe(line, data);
  data->path = ft_calloc(sizeof(char *), data->pipe_nbr + 2);
  return (TRUE);
}
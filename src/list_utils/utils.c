#include "../../include/minishell.h"

int ft_isalphalen(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (ft_isalpha(str[i]) != 0 || str[i] == '_')
      i++;
    else
      break;
  }
  return (i);
}

char  *replace_var(char *str, t_data *data)
{
  int i;
  char *tmp;
  char *var;
  char *end;

  i = is_dollar(str);
  tmp = ft_substr(str, i,  ft_isalphalen(&str[i]));
  end = NULL;
  if (do_var_exist(data, tmp) == TRUE)
    var = ft_substr(get_env_var(tmp, data)->str, ft_strlen(tmp) + 1, ft_strlen(get_env_var(tmp, data)->str) - ft_strlen(tmp) + 1);
  else
  {
    var = ft_substr(str, 0, i - 1);
    if (ft_strlen(var) == ft_strlen(str) - (ft_strlen(tmp) + 1))
      return (var);
    var = ft_strjoin(var, &str[i + ft_strlen(tmp)]);
    free(tmp);
    return (var);
  }
  if (ft_strlen(tmp) != ft_strlen(str))
    end = ft_strdup(&str[i + ft_isalphalen(&str[i])]);
  free(tmp);
  if (i - 1 != 0)
  {
    tmp = ft_substr(str, 0, i-1);
    tmp = ft_strjoin(tmp, var);
  }
  else
    tmp = var;
  if (end)
  {
    tmp = ft_strjoin(tmp, end);
    free(end);
  }
  free(str);
  return (tmp);
}

int tablen(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    i++;
  return(i);
}

int is_dollar(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (ft_strlen(str) == 1)
      return(-1);
    else if (str[i + 1] == '$')
      i++;
    else if (str[i] == '$')
      return (i + 1);
    else
      i++;
  }
  return (-1);
}

void setup_arg(t_token *token)
{
  t_token *it;
  int i;
  int len;
  char  **arg;

  if (last_token(token) != token)
    it = token->next;
  else
    it = NULL;
  len = countarg(it) + 1;
  arg = malloc(sizeof(char *) * (len + 1));
  i = 1;
  if (token->builtins == FALSE)
    arg[0] = ft_strdup(token->path);
  else
    arg[0] = ft_strdup(token->str);
  while (len > i && (it->type == ARG || it->type == PARAM))
  {
    arg[i] = ft_strdup(it->str);
    i++;
    it = it->next;
  }
  arg[i] = NULL;
  token->arg = arg;
  return ;
}
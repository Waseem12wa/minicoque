#include "../../include/minishell.h"

int choose_token(t_list  *lst, t_token *token)
{
  if (lst->str[0] == '|')
    return (PIPE);
  if (ft_lstlast(lst) != lst)
  {
  if (lst->str[0] == '>' && lst->next->str[0] == '>')
    return (APPEND);
  if (lst->str[0] == '<' && lst->next->str[0] == '<')
    return (HEREDOC);
  }
  if (lst->str[0] == '<')
    return (INPUT);
  if (lst->str[0] == '>')
    return (TRUNC);
  if (lst->str[0] == '-')
    return (PARAM);
  if (token != NULL)
  {
    if (token->type == CMD || token->type == PARAM || token->type == ARG || token->type == TRUNC || token->type == APPEND)
     return (ARG);
    if (token->type == PIPE)
      return (CMD);
  }
  return (CMD);
}


bool token_setup(t_data *data)
{
  t_list *it;
  int toktok;

  it = data->cmd;
  if (!data->cmd)
    return (FALSE);
  data->token = NULL;
  while (it)
  {
    toktok = choose_token(it, last_token(data->token));
    if (toktok == HEREDOC)
    {
      token_add_back(&(data->token), token_create(ft_strjoin(it->str, it->next->str), toktok));
      it = it->next->next;
    }
    else if (toktok == APPEND)
    {
      token_add_back(&(data->token), token_create(ft_strjoin(it->str, it->next->str), toktok));
      it = it->next->next;
    }
    else
    {
    token_add_back(&(data->token), token_create(ft_strdup(it->str), toktok));
    it = it->next;
    }
  }
  return (TRUE);
}
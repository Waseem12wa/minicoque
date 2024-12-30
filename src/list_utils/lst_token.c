#include "../../include/minishell.h"

t_token *token_create(char *str, int token)
{
  t_token *new;

  new = malloc(sizeof(t_token));
  if (!new)
    return (NULL);
  if (str[0] == '\'' || str[0] == '\"')
  {
    new->str = ft_substr(str, 1, ft_strlen(str) - 2);
    if (str[0] == '\'')
    {
      new->sq = TRUE;
      new->dq = FALSE;
    }
    else if (str[0] == '\"')
    {
        new->sq = FALSE;
        new->dq = TRUE;
    }
  }
  else
  {
  new->str = str;
  new->dq = FALSE;
  new->sq = FALSE;
  }
  new->path = NULL;
  new->prev = NULL;
  new->arg = NULL;
  new->next = NULL;
  new->type = token;
  return (new);
}

t_token *last_token(t_token *lst)
{
  t_token	*it;

  it = lst;
  if (lst == NULL)
    return (NULL);
  while (it->next != NULL)
    it = it->next;
  return (it);
}

void	token_add_back(t_token **lst, t_token *new)
{
  t_token	*it;

  if (!new)
    return;
  if (lst && *lst)
  {
    it = *lst;
    while (it->next)
      it = it->next;
    it->next = new;
  }
  else if (lst)
    *lst = new;
}

void	deltok(t_token *lst, void (*del)(void *))
{
  if (!del || !lst)
		return ;
	del(lst->str);
	free(lst);
}

void	token_clear(t_token **lst, void (*del)(void *))
{
  t_token	*it;
  
  if (!del || !lst)
    return ;
  while (*lst)
  {
    it = (*lst)->next;
    deltok(*lst, del);
    *lst = it;
  }
  *lst = NULL;
}

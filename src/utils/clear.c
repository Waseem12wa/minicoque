#include "../../include/minishell.h"

void clear_tab(char **tab)
{
  int i;

  if (!tab)
      return;

  i = 0;
  while (tab[i])
  {
      free(tab[i]);
      i++;
  }
  free(tab);
  tab = NULL; 
}

void clear_2tab(char ***tab)
{
    int i;

    if (!tab || !*tab)
        return;
    i = 0;
    while ((*tab)[i]) // Compte le nombre de sous-tableaux
        i++;

    while (i > 0) // Libère les sous-tableaux en ordre inverse
    {
        i--;
        free((*tab)[i]);
    }
    free(*tab);
}

void clear_single(t_data *data)
{
    free(data->prompt);
    //free(data->user);
}

void clear_all(t_data *data)
{
    if (data->path)
        clear_tab(data->path);
    if (data->env)
        env_clear(&data->env, free);
    if (data->args) {
        clear_2tab(data->args);
        free(data->args);
    }
    if (data->cmd)
        ft_lstclear(&(data->cmd), free);
    if (data->token)
        token_clear(&(data->token), free);
    clear_single(data);
}
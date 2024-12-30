#include "../../include/minishell.h"

void clear_tab(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void clear_2tab(char ***tab)
{
  int i;

  i = 0;
  while (tab[i])
    clear_tab(tab[i++]);
  free(tab);
    
}

void clear_all(t_data *data)
{
  clear_2tab(data->args);
  clear_tab(data->path);
}
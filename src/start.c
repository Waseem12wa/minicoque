/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillot <bguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:49:25 by bguillot          #+#    #+#             */
/*   Updated: 2024/10/08 14:51:06 by bguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void       starting_message(void) 
{
  printf("            \033[0;93m____\033[0;36m_         \033[0;93m____\033[0;36m_    "         "                                 \n");
  printf("\033[0;93m___\033[0;36m____ ___ \033[0;93m___\033[0;36m(_)\033[0;93m___\033[0;36m____ "         "\033[0;93m___\033[0;36m(_)\033[0;93m__\033[0;36m_____\033[0;93m__\033[0;36m____ \033[0;93m__\033[0;36m____ \033[0;93m___\033[0;36m__  __\033[0;93m__\033[0;36m___ \n");
  printf("\033[0;93m__\033[0;36m/ __ `__ \\\033[0;93m__\033[0;36m/ / \033[0;93m__\033[0;36m/ __ \\\033[0;93m__\033[0;36m/ / "         "\033[0;93m_\033[0;36m/ ___/\033[0;93m_\033[0;36m/ __ \\\033[0;93m_\033[0;36m/ __ `/\033[0;93m_\033[0;36m/ / / /\033[0;93m_\033[0;36m/ _ \\\n");
  printf("\033[0;93m_\033[0;36m/ / / / / /\033[0;93m_\033[0;36m/ /  "         "\033[0;93m_\033[0;36m/ / / /\033[0;93m_\033[0;36m/ /  / "         "/__  / /_/ // /_/ / / /_/ / /  __/\n");
  printf("/_/ /_/ /_/ /_/   /_/ /_/ /_/   \\___/  \\____/ \\__  /  \\____/  "         "\\___/ \n");
  printf("                                                /_/                 \n\033[0;0m \n");
}

void  list_path_setup(t_data *data)
{
  int  i;
  
  data->list_path = ft_split(data->minishell_path, ":");
  i = 0;
  while(data->list_path[i])
    {
      if (access(data->list_path[i], X_OK) == -1)
        printf("\033[0;31mERROR : '%s' is not a valid path\033[0;0m\n", data->list_path[i]);
      i++;
    }
}

void  path_setup(char **env, t_data *data)
{
  int i;

  i = 0;
  while (env[i])
  {
    if (ft_strnstr(env[i], "PATH=", 5))
    {
      data->p_index = i;
      data->minishell_path = &(env[i][5]);
      return;
    }
    i++;
  }
  if (!data->minishell_path)
    data->minishell_path = strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
  return;
}

void  env_setup(char **env, t_data *data)
{
  int i;

  data->env = env_create(env[0], 0);
  i = 1;
  while (env[i])
  {
    env_add_back(&data->env, env_create(env[i], i));
    i++;
  }
}

void  setup(char **env, t_data *data)
{
  starting_message();
  path_setup(env, data);
  env_setup(env, data);
  data->user = getenv("USER");
  data->fd_in = dup(0);
  data->fd_out = dup(1);
  list_path_setup(data);
}

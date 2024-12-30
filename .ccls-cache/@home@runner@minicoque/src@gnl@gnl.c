/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:59:35 by grouger           #+#    #+#             */
/*   Updated: 2024/01/18 16:32:56 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_next_line(int fd)
{
  static char	*stash;
  char		*buffer;
  char		*line;
  int			b_read;
  char		*tmp;

  b_read = 1;
  if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
    return (NULL);
  buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
  while (b_read > 0)
  {
    b_read = read(fd, buffer, BUFFER_SIZE);
    if (b_read <= 0 && ft_strlen(stash) == 0)
      return (ft_free(stash, buffer, NULL));
    if (!stash)
      stash = ft_strdup("");
    stash = ft_strjoin(stash, buffer, b_read);
    if (ft_strchr(stash, '\n') != NULL)
      break ;
  }
  tmp = stash;
  line = get_line(stash);
  stash = ft_substr(tmp, ft_strlen(line), ft_strlen(stash) - ft_strlen(line));
  return (ft_free(buffer, tmp, line));
}

char	*get_line(char *stash)
{
  char	*line;
  int		i;

  i = 0;
  while (stash[i] && stash[i] != '\n')
    i++;
  line = ft_substr(stash, 0, i + 1);
  return (line);
}

char	*ft_free(char *stash, char *buffer, char *str)
{
  free(stash);
  free(buffer);
  if (str == NULL)
    return (NULL);
  else
    return (str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:03:02 by grouger           #+#    #+#             */
/*   Updated: 2024/01/18 16:30:38 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strjoin(char *s1, char *s2, int b_read)
{
  unsigned char	*ptr;
  int				i;
  int				j;

  s2[b_read] = '\0';
  if (!s1)
    return (NULL);
  ptr = malloc(sizeof(char) * (ft_strlen(s1)+ ft_strlen(s2) + 1));
  if (!ptr)
    return (NULL);
  i = -1;
  j = 0;
  while (s1[++i])
    ptr[i] = s1[i];
  while (s2[j])
  {
    ptr[i] = s2[j];
    ++i;
    ++j;
  }
  ptr[i] = '\0';
  free(s1);
  return ((char *)ptr);
}

int	ft_strlen(const char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    ++i;
  return (i);
}

char	*ft_strchr(const char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != 0)
  {
    if (str[i] == c)
      return ((char *) &str[i]);
    if (str[i + 1] == c)
      return ((char *) &str[i + 1]);
    i++;
  }
  return (NULL);
}

char	*ft_strdup(const char *s)
{
  char	*dup;
  int		i;

  i = 0;
  dup = malloc(sizeof(const char) * (ft_strlen(s) + 1));
  if (!dup)
    return (NULL);
  while (s[i])
  {
    dup[i] = s[i];
    ++i;
  }
  dup[i] = '\0';
  return (dup);
}

char	*ft_substr(char const *s, int start, int len)
{
  int		i;
  char	*new;

  i = 0;
  if (!s)
    return (NULL);
  if (ft_strlen(s) < start)
    return (ft_strdup(""));
  if (ft_strlen(s) - start < len)
    len = ft_strlen(s) - start;
  if (ft_strlen(s) < len)
    len = ft_strlen(s);
  if (len < 0)
    len = 0;
  new = malloc(sizeof(char) * len + 1);
  if (!new)
    return (NULL);
  while (s[start] != '\0' && i < len)
  {
    new[i] = s[start];
    ++i;
    ++start;
  }
  new[i] = '\0';
  return (new);
}
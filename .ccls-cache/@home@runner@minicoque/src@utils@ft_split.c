/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:36:58 by grouger           #+#    #+#             */
/*   Updated: 2023/11/03 14:55:15 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_fo(const char *s, char tof)
{
  int	i;

  i = 0;
  while (s[i])
  {
    if (s[i] == tof)
      return (i);
    ++i;
  }
  return (0);
}

static int	ft_strcount(char const *s1, char c)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  if (!s1)
    return (0);
  while (s1[i])
  {
    if (s1[i] == c && s1[i + 1] != c && s1[i + 1])
      ++res;
    else if (s1[i] != c && i == 0)
      res++;
    ++i;
  }
  return (res + 1);
}

static char	**ft_clear(char **res, int i)
{
  while (res[--i] && i >= 0)
    free(res[i]);
  return (res);
}

char	**ft_split(char const *s, char c)
{
  char	**res;
  int		j;
  size_t	w_len;

  res = (char **)ft_calloc(sizeof(void *), ft_strcount(s, c));
  if (!res || !s)
    return (NULL);
  j = 0;
  while (*s)
  {
    while (*s == c && *s)
      ++s;
    if (*s)
    {
      if (!ft_fo(s, c))
        w_len = ft_strlen(s);
      else
        w_len = ft_fo(s, c);
      res[j++] = ft_substr(s, 0, w_len);
      if (!res[j - 1])
        return (ft_clear(res, j - 1));
      s += w_len;
    }
  }
  return (res);
}
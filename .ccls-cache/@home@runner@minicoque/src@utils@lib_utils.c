/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:18:36 by grouger           #+#    #+#             */
/*   Updated: 2024/10/08 14:18:36 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
  size_t			i;
  unsigned char	*p;

  i = 0;
  p = s;
  while (i < n)
    p[i++] = '\0';
}

void	*ft_calloc(size_t nm, size_t n)
{
  void	*result;

  if ((nm * n > INT32_MAX) || (nm > UINT16_MAX && n > UINT16_MAX))
    return (NULL);
  result = malloc(nm * n);
  if (!result)
    return (NULL);
  ft_bzero(result, nm * n);
  return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
  size_t	i;
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
  new = ft_calloc(sizeof(char), len + 1);
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

char	*ft_strdup(const char *s)
{
  char	*dup;
  int		i;

  i = 0;
  dup = ft_calloc(sizeof(const char), ft_strlen(s) + 1);
  if (!dup)
    return (NULL);
  while (s[i])
  {
    dup[i] = s[i];
    ++i;
  }
  return (dup);
}

char	*ft_strnstr(const char *str, const char *srch, size_t n)
{
  int		i;
  char	*s;

  if ((!str || !srch) && (n == 0))
    return (NULL);
  i = 0;
  s = (char *)str;
  if (ft_strncmp(srch, "", 1) == 0)
    return (s);
  while (s[i] && i + ft_strlen(srch) - 1 < n)
  {
    if (ft_strncmp(&s[i], srch, ft_strlen(srch)) == 0)
      return ((char *)&s[i]);
    ++i;
  }
  return (NULL);
}
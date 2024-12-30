#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
  char	*dup;
  int		i;

  i = 0;
  dup = ft_calloc(sizeof(const char), ft_strlen(s) + 1);
  if (!dup)
    return (NULL);
  while (s[i] && i < n)
  {
    dup[i] = s[i];
    ++i;
  }
  return (dup);
}

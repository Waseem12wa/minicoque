/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:46:35 by grouger           #+#    #+#             */
/*   Updated: 2023/11/01 17:52:25 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

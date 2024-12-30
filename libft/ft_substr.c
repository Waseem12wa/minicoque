/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:32:29 by grouger           #+#    #+#             */
/*   Updated: 2023/11/07 12:38:37 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

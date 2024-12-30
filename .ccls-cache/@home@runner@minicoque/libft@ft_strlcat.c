/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:47:28 by grouger           #+#    #+#             */
/*   Updated: 2023/11/03 16:09:12 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;

	if (!dst && size == 0)
		return (0);
	j = ft_strlen(src);
	i = ft_strlen(dst);
	l = i + j;
	if (size == 0)
		return (j);
	while (!dst && size > 0)
		i++;
	j = 0;
	while ((src[j]) && (i < size - 1))
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	if (size < i)
		return (size + ft_strlen(src));
	return (l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:27:46 by grouger           #+#    #+#             */
/*   Updated: 2023/11/01 18:41:08 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mb, int sc, size_t n)
{
	unsigned char	*ptr;
	unsigned char	cmp;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)mb;
	cmp = sc;
	while (i < n)
	{
		if (ptr[i] == cmp)
			return (&ptr[i]);
		++i;
	}
	return (NULL);
}

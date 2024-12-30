/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:43:20 by grouger           #+#    #+#             */
/*   Updated: 2023/11/01 19:13:37 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *f, const void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *) f;
	ptr2 = (unsigned char *) s;
	while (i < n)
	{
		if (ptr1[i] - ptr2[i] != 0)
			return (ptr1[i] - ptr2[i]);
		else
			++i;
	}
	return (0);
}

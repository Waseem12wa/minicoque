/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:01:21 by grouger           #+#    #+#             */
/*   Updated: 2023/10/31 12:16:00 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *sourc, size_t size)
{
	unsigned const char	*temp1;
	unsigned char		*temp2;
	size_t				i;

	i = 0;
	temp1 = sourc;
	temp2 = dest;
	if (!dest && !sourc)
		return (dest);
	while (i < size)
	{
		temp2[i] = temp1[i];
		i++;
	}
	return (dest);
}

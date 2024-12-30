/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:14:23 by grouger           #+#    #+#             */
/*   Updated: 2023/11/03 16:05:06 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned const char	*temp1;
	unsigned char		*temp2;

	if (!src && !dst)
		return (NULL);
	temp1 = (unsigned const char *)src;
	temp2 = (unsigned char *)dst;
	if (src >= dst)
	{
		while (size--)
			*temp2++ = *temp1++;
		return (dst);
	}
	else
	{
		temp2 = temp2 + size - 1;
		temp1 = temp1 + size - 1;
		while (size--)
			*temp2-- = *temp1--;
		return (dst);
	}
	return (dst);
}

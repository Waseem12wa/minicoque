/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:29:18 by grouger           #+#    #+#             */
/*   Updated: 2023/11/02 15:41:11 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *p, int value, size_t count)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = p;
	while (i < count)
		s[i++] = value;
	return (p);
}

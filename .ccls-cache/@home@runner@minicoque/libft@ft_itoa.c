/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:06:08 by grouger           #+#    #+#             */
/*   Updated: 2023/11/08 16:01:34 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		++i;
	}
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned char	*res;
	int				i;
	long			s;

	s = n;
	if (s == 0)
		return (ft_strdup("0"));
	i = ft_pow(s);
	res = ft_calloc(sizeof(char), ft_pow(s) + 1);
	if (!res)
		return (NULL);
	if (s < 0)
	{
		s = -s;
		res[0] = '-';
		i = ft_pow(s) + 1;
	}
	res[i] = '\0';
	while (s > 0)
	{
		--i;
		res[i] = (s % 10) + '0';
		s = s / 10;
	}
	return ((char *)res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:56:53 by grouger           #+#    #+#             */
/*   Updated: 2023/11/06 13:05:55 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	j;

	j = 0;
	if (ft_strlen(str) == 0 && c != 0)
		return (NULL);
	if (c > 256)
		c = c % 256;
	while (str[j] != '\0')
		j++;
	while (str[j] != c)
	{
		if (str[j -1] == '\0')
			return (NULL);
		j--;
		if (j < 0)
			return (NULL);
	}
	return ((char *) &str[j]);
}

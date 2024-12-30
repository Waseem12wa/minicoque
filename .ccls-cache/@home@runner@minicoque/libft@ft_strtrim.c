/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:58:58 by grouger           #+#    #+#             */
/*   Updated: 2023/11/07 12:43:49 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isin(const char c, const char *tof)
{
	int	i;

	i = 0;
	while (tof[i])
	{
		if (c == tof[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				end;
	int				start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isin(s1[start], set) == 1 || ft_isin(s1[end], set))
	{
		if (ft_isin(s1[start], set))
			++start;
		if (ft_isin(s1[end], set))
			--end;
	}
	return ((char *)ft_substr(s1, start, end - start + 1));
}

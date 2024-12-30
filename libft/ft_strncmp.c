/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:52:01 by grouger           #+#    #+#             */
/*   Updated: 2023/11/01 15:12:30 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(const char *f, const char *s, size_t size)
{
	unsigned char	*char_f;
	unsigned char	*char_s;
	size_t			i;

	i = 0;
	if (size == 0)
		return (0);
	char_f = (unsigned char *)f;
	char_s = (unsigned char *)s;
	while ((f[i] || s[i]) && i < size)
	{
		if ((char_f[i] < (char_s[i]) || (char_f[i] > char_s[i])))
			return (char_f[i] - char_s[i]);
		else
			i++;
	}
	return (0);
}

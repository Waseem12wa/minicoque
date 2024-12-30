/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:57:36 by grouger           #+#    #+#             */
/*   Updated: 2023/11/08 15:03:01 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nm, size_t n)
{
	void	*result;

	if ((nm * n > INT32_MAX) || (nm > UINT16_MAX && n > UINT16_MAX))
		return (NULL);
	result = malloc(nm * n);
	if (!result)
		return (NULL);
	ft_bzero(result, nm * n);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:16:40 by grouger           #+#    #+#             */
/*   Updated: 2023/11/08 15:30:17 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = ft_calloc(sizeof(t_list), 1);
	if (new == NULL)
		return (NULL);
	new->str = content;
	new->next = NULL;
	return (new);
}

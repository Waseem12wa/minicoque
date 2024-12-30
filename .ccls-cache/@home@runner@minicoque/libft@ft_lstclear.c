/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:30 by grouger           #+#    #+#             */
/*   Updated: 2023/11/08 15:02:57 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*it;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		it = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = it;
	}
	*lst = NULL;
}

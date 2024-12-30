/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grouger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:27:43 by grouger           #+#    #+#             */
/*   Updated: 2023/11/08 16:09:20 by grouger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	if (!lst || !del || !f)
		return (NULL);
	start = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->str));
		if (!new)
			ft_lstclear(&new, *del);
		lst = lst->next;
		ft_lstadd_back(&start, new);
	}
	return (start);
}

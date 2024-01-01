/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:53:33 by schibane          #+#    #+#             */
/*   Updated: 2023/03/30 23:10:47 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*p;
	t_list	*elem;

	if (!lst || !f || !del)
		return (NULL);
	p = lst;
	newlist = NULL;
	while (p)
	{
		elem = ft_lstnew((*f)(p->content));
		if (!elem)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, elem);
		p = p->next;
	}
	return (newlist);
}

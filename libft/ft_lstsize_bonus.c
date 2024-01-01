/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:13:02 by schibane          #+#    #+#             */
/*   Updated: 2023/03/30 15:35:47 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;

	if (lst == NULL)
		return (0);
	i = 1;
	p = lst;
	while (p->next != NULL)
	{
		i ++;
		p = p->next;
	}
	return (i);
}

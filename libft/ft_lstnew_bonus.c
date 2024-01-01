/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:11:26 by schibane          #+#    #+#             */
/*   Updated: 2023/03/28 23:31:51 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*noeud;

	noeud = malloc(sizeof(t_list));
	if (!noeud)
		return (NULL);
	noeud->content = content;
	noeud->next = NULL;
	return (noeud);
}

// int main()
// {
// 	t_list *p;
// 	int num = 5;

// 	void *z = &num;
// 	p = ft_lstnew(z);
// 	return (0);
// }
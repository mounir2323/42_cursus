/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:50:13 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/26 22:03:49 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	normal_add(char *str, t_list **result, int index)
{
	char	**tab;
	int		i;
	t_list	*node;

	tab = ft_split(str, ' ');
	i = 1;
	if (!*result || !index)
	{
		node = ft_lstnew(tab[0]);
		ft_lstadd_back(result, node);
	}
	else
	{
		node = ft_lstlast(*result);
		node->content = ft_strjoin((char *)node->content, tab[0]);
	}
	while (tab[i])
	{
		node = ft_lstnew(tab[i]);
		ft_lstadd_back(result, node);
		i ++;
	}
}

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	get_result_args(t_list *tokens, t_list **result)
{
	t_list	*tmp;
	char	*cont;
	int		i;

	tmp = tokens;
	i = 0;
	while (tmp)
	{
		cont = tmp->content;
		if (*cont == '\"')
			trim_quotes_add(tmp->content, result, i);
		else if (*cont == '\'')
			trim_s_quotes_add(tmp->content, result, i);
		else
			normal_add(tmp->content, result, i);
		tmp = tmp->next;
		i ++;
	}
}

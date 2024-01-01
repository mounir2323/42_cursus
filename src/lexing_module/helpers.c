/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:23:00 by schibane          #+#    #+#             */
/*   Updated: 2023/12/07 20:09:26 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	count_comands(t_list *lst_input)
{
	unsigned int	len;
	t_list			*tmp;

	len = 1;
	tmp = lst_input;
	while (tmp)
	{
		if (!ft_strcmp((char *)tmp->content, "|"))
			len ++;
		tmp = tmp->next;
	}
	return (len);
}

t_command	*create_command(unsigned int i)
{
	t_command	*com;

	com = malloc(sizeof(t_command));
	if (!com)
		return (NULL);
	com->args_list = NULL;
	com->name = NULL;
	com->nbr = i + 1;
	com->path = NULL;
	com->out_redir_list = NULL;
	com->in_redir_list = NULL;
	return (com);
}

bool	is_redir_operator(char *str)
{
	return (!ft_strcmp(str, ">") || !ft_strcmp(str, ">>")
		|| !ft_strcmp(str, "<") || !ft_strcmp(str, "<<"));
}

t_redir	*create_redirection(char *path, t_redir_type type)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->path_file = ft_strdup(path);
	redir->type = type;
	return (redir);
}

void	add_redirection_list(t_list **redir_list, char *path, t_redir_type type)
{
	t_redir	*redir;
	t_list	*node;

	redir = create_redirection(path, type);
	node = ft_lstnew(redir);
	ft_lstadd_back(redir_list, node);
}

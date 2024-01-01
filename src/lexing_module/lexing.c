/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:19:15 by schibane          #+#    #+#             */
/*   Updated: 2023/12/09 19:17:10 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_command_arg(t_list *current, t_list **args_list)
{
	char	*arg;
	t_list	*node;

	arg = ft_strdup(current->content);
	node = ft_lstnew(arg);
	ft_lstadd_back(args_list, node);
}

void	redirections_dispatcher(t_list *current, t_command *command)
{
	if (!ft_strcmp((char *) current->content, "<"))
		add_redirection_list(&command->in_redir_list,
			current->next->content, INPUT_REDIR);
	else if (!ft_strcmp((char *) current->content, "<<"))
		add_redirection_list(&command->in_redir_list,
			current->next->content, HERE_DOC);
	else if (!ft_strcmp((char *) current->content, ">"))
		add_redirection_list(&command->out_redir_list,
			current->next->content, OUTPUT_REDIR);
	else
		add_redirection_list(&command->out_redir_list,
			current->next->content, OUTPUT_APPEND);
}

t_list	*get_command_node(t_list *input_list, unsigned int i
		, t_list **command_list)
{
	t_list		*node;
	t_command	*command;
	t_list		*tmp;

	tmp = input_list;
	command = create_command(i);
	while (tmp && ft_strcmp((char *) tmp->content, "|"))
	{
		if (is_redir_operator((char *) tmp->content))
		{
			redirections_dispatcher(tmp, command);
			tmp = tmp->next;
		}
		else
			get_command_arg(tmp, &command->args_list);
		tmp = tmp->next;
	}
	node = ft_lstnew(command);
	ft_lstadd_back(command_list, node);
	if (tmp)
		tmp = tmp->next;
	return (tmp);
}

t_list	*lexing_input(t_list *lst_input)
{
	t_list			*command_lst;
	unsigned int	count;
	unsigned int	i;
	t_list			*tmp;

	command_lst = NULL;
	i = 0;
	count = count_comands(lst_input);
	tmp = lst_input;
	while (i < count)
	{
		tmp = get_command_node(tmp, i, &command_lst);
		i ++;
	}
	return (command_lst);
}

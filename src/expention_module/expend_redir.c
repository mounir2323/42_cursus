/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:21:59 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 20:49:53 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expend_redir(t_redir *redir, t_config *config)
{
	t_list	*tokens;
	t_list	*result;

	tokens = tokenize(redir->path_file, config);
	result = NULL;
	get_result_args(tokens, &result);
	if (result->next)
	{
		ft_lstclear(&result, free);
		ft_lstclear(&tokens, free);
		return (printf("%s: ambiguous redirect\n", redir->path_file), false);
	}
	free(redir->path_file);
	redir->path_file = ft_strdup((char *)result->content);
	ft_lstclear(&result, free);
	ft_lstclear(&tokens, free);
	return (true);
}

bool	expend_redirs(t_command *command, t_config *config)
{
	bool			correct;
	t_list			*redir_list;
	t_redir			*redir;

	correct = true;
	redir_list = command->in_redir_list;
	while (redir_list)
	{
		redir = (t_redir *)redir_list->content;
		if (redir->type != HERE_DOC)
			correct = expend_redir(redir, config);
		if (!correct)
			return (false);
		redir_list = redir_list->next;
	}
	redir_list = command->out_redir_list;
	while (redir_list)
	{
		redir = (t_redir *)redir_list->content;
		correct = expend_redir(redir, config);
		if (!correct)
			return (false);
		redir_list = redir_list->next;
	}
	return (correct);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expention.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:10:44 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 20:59:15 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*tokenize(char *str, t_config *config)
{
	t_list	*token;
	int		i;

	token = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			i += replace_dollar_sign(str, i, &token, config);
		else if (str[i] == '\'')
			i += skip_quotes(str, i, &token);
		else if (str[i] == '\"')
			i += handle_dollar_indouble_q(str, i + 1, &token, config);
		else
			i += copy_until_limit(str, i, &token);
	}
	return (token);
}

char	*join_tokens(t_list *tokens)
{
	t_list	*tmp;
	char	*res;

	tmp = tokens;
	res = NULL;
	while (tmp)
	{
		res = ft_strjoinnn(res, (char *)tmp->content);
		tmp = tmp->next;
	}
	return (res);
}

t_list	*expand_command_args(t_config *config,
					t_command *command)
{
	t_list	*result;
	t_list	*tokens;
	t_list	*tmp;

	result = NULL;
	tmp = command->args_list;
	while (tmp)
	{
		tokens = tokenize((char *)tmp->content, config);
		get_result_args(tokens, &result);
		tmp = tmp->next;
	}
	return (result);
}

void	expansion_loop(t_list *command_list, t_config *config)
{
	t_list		*tmp;
	t_list		*expended_args;
	t_command	*command;

	expended_args = NULL;
	tmp = command_list;
	while (tmp)
	{
		command = tmp->content;
		expended_args = expand_command_args(config, command);
		ft_lstclear(&command->args_list, free);
		command->args_list = expended_args;
		tmp = tmp->next;
	}
}

bool	expansion(t_list *command_list, t_config *config)
{
	t_list		*tmp;
	t_command	*command;
	bool		correct;

	expansion_loop(command_list, config);
	correct = true;
	tmp = command_list;
	while (tmp)
	{
		command = tmp->content;
		correct = expend_redirs(command, config);
		if (!correct)
			return (false);
		tmp = tmp->next;
	}
	return (correct);
}

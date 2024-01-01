/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:57:46 by schibane          #+#    #+#             */
/*   Updated: 2023/12/20 15:42:06 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_missing_quotes(char *str)
{
	unsigned int	i;
	char			*c;

	i = 0;
	c = NULL;
	while (str[i])
	{
		if (is_double_quote(str[i]) || is_single_quote(str[i]))
		{
			c = strchr(&str[i + 1], str[i]);
			if (!c)
				return (true);
			i += (c - &str[i]) + 1;
		}
		else
			i ++;
	}
	return (false);
}

bool	is_syntax_error(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!ft_strcmp(lst->content, "|"))
		return (printf("bash: syntax error near unexpected token `|'\n"), true);
	while (tmp)
	{
		if (is_operator(*((char *)tmp->content)) && tmp->next
			&& (is_operator(*((char *)tmp->next->content))
				|| *((char *)tmp->next->content) == '|'))
			return (printf
				("bash: syntax error near unexpected token `%s'\n",
					((char *)tmp->next->content)), true);
		else if (is_operator(*((char *)tmp->content)) && !tmp->next)
			return (printf
				("bash: syntax error near unexpected token `newline'\n"), true);
		else if (!tmp->next && !ft_strcmp((char *)tmp->content, "|"))
			return (printf
				("bash: syntax error near unexpected token `|'\n"), true);
		tmp = tmp->next;
	}
	return (false);
}

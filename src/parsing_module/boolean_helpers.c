/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:12:03 by schibane          #+#    #+#             */
/*   Updated: 2023/12/07 19:54:13 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_double_quote(char c)
{
	return (c == '\"');
}

bool	is_single_quote(char c)
{
	return (c == '\'');
}

bool	is_operator(char c)
{
	return (c == '<' || c == '>');
}

bool	is_double_operator(char *str, unsigned int i)
{
	return (
		(str[i] == '<' && str[i + 1] == '<')
		|| (str[i] == '>' && str[i + 1] == '>'));
}

bool	is_word_limits(char *str, unsigned int i)
{
	return (str[i] == ' '
		|| is_operator(str[i]) || str[i] == '\0');
}

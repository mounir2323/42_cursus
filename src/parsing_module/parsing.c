/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:35:36 by schibane          #+#    #+#             */
/*   Updated: 2023/12/26 20:27:28 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_word_start(char *str, unsigned int i)
{
	return ((i == 0 && !is_word_limits(str, i))
		|| (i != 0 && !is_word_limits(str, i) && is_word_limits(str, i - 1)));
}

bool	is_pipe_at_end(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (!str[i + 1] && str[i] == '|')
			return (true);
		i ++;
	}
	return (false);
}

char	*read_again(char *str)
{
	char	*read;
	char	*joined_read;
	char	*res;
	bool	quotes;

	quotes = is_missing_quotes(str);
	read = readline("> ");
	if (!read)
		return (str);
	if (quotes)
		joined_read = ft_strjoin("\n", read);
	else
		joined_read = ft_strdup(read);
	res = ft_strjoin(str, joined_read);
	free(str);
	free(read);
	free(joined_read);
	return (res);
}

char	*read_input(char *input_str)
{
	char	*new;

	if (input_str)
		free(input_str);
	new = readline("minishell 1.0 % ");
	if (!new)
		exit(0);
	while (is_missing_quotes(new))
		new = read_again(new);
	return (new);
}

t_list	*parsing_arguments(void)
{
	char	*inputs_str;
	t_list	*inputs_list;

	inputs_str = NULL;
	inputs_str = read_input(inputs_str);
	if (!*inputs_str)
		return (free(inputs_str), NULL);
	add_history(inputs_str);
	inputs_list = split_args(inputs_str);
	free(inputs_str);
	if (is_syntax_error(inputs_list))
		return (NULL);
	return (inputs_list);
}

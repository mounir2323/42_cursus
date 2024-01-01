/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:27:51 by schibane          #+#    #+#             */
/*   Updated: 2023/12/25 22:57:33 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	replace_dollar_sign_inquotes(t_config *config,
			char *str, char **result)
{
	unsigned int	len;
	char			*sub;
	char			*value;

	len = str_chr_closest(str + 1, "\" $\'") - (str);
	if (len == 0)
		return (1);
	sub = ft_substr(str + 1, 0, len - 1);
	value = get_variable_value(sub, config);
	if (!value)
		return (free(sub), len);
	*result = ft_strjoinnn(*result, value);
	free(sub);
	return (len);
}

unsigned int	copy_until_limit_inq(char *str, int i, char **result)
{
	int		len;
	char	*sub;

	len = (str_chr_closest(&str[i], "$\"") - &str[i]);
	sub = ft_substr(&str[i], 0, len);
	*result = ft_strjoinnn(*result, sub);
	free(sub);
	return (len);
}

unsigned int	handle_dollar_indouble_q(char *str, int i,
		t_list **token, t_config *config)
{
	unsigned int	len;
	unsigned int	j;
	char			*result;
	t_list			*node;

	len = strchr(&str[i], '\"') - &str[i];
	j = 0;
	result = NULL;
	result = ft_strjoinnn(result, "\"");
	if (len == 0)
		return (2);
	while (j < len)
	{
		if (str[i + j] == '$')
			j += replace_dollar_sign_inquotes(config,
					&str [i + j], &result);
		else
			j += copy_until_limit_inq(str, i + j, &result);
	}
	result = ft_strjoinnn(result, "\"");
	node = ft_lstnew(result);
	ft_lstadd_back(token, node);
	return (len + 2);
}

void	trim_quotes_add(char *str, t_list **result, int i)
{
	char	*trimed;
	t_list	*node;

	trimed = ft_strtrim(str, "\"");
	if (!*result || !i)
	{
		node = ft_lstnew(trimed);
		ft_lstadd_back(result, node);
	}
	else
	{
		node = ft_lstlast(*result);
		node->content = ft_strjoin((char *)node->content, trimed);
	}
}

void	trim_s_quotes_add(char *str, t_list **result, int i)
{
	char	*trimed;
	t_list	*node;

	trimed = ft_strtrim(str, "\'");
	if (!*result || !i)
	{
		node = ft_lstnew(trimed);
		ft_lstadd_back(result, node);
	}
	else
	{
		node = ft_lstlast(*result);
		node->content = ft_strjoin((char *)node->content, trimed);
	}
}

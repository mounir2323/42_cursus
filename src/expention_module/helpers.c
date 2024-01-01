/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:19:59 by schibane          #+#    #+#             */
/*   Updated: 2023/12/20 18:39:11 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_variable_value(char *str, t_config *config)
{
	t_env	*tmp;

	tmp = config->env;
	if (!ft_strcmp(str, "?"))
		return (ft_itoa(config->status_code));
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->variable))
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

unsigned int	skip_quotes(char *str, int i, t_list **tokens)
{
	unsigned int	len;
	char			*sub;
	t_list			*node;

	len = (ft_strchr(&str[i + 1], '\'') - &str[i + 1]);
	if (len == 0)
		return (1);
	sub = ft_substr(&str[i], 0, len + 2);
	node = ft_lstnew(sub);
	ft_lstadd_back(tokens, node);
	return (len + 2);
}

char	*str_chr_closest(char *str, char *delimiteurs)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (delimiteurs[j])
		{
			if (str[i] == delimiteurs[j])
				return (&str[i]);
			j ++;
		}
		i ++;
	}
	return (&str[i]);
}

unsigned int	replace_dollar_sign(char *str, int i,
		t_list **tokens, t_config *config)
{
	int		len;
	char	*sub;
	t_list	*node;
	char	*value;

	len = (str_chr_closest(&str[i + 1], "$\'\"\0") - &str[i + 1]);
	if (len == 0)
		return (1);
	sub = ft_substr(&str[i + 1], 0, len);
	value = get_variable_value(sub, config);
	free(sub);
	if (!value)
		return (len + 1);
	node = ft_lstnew(value);
	ft_lstadd_back(tokens, node);
	return (len + 1);
}

unsigned int	copy_until_limit(char *str, int i, t_list **tokens)
{
	int		len;
	char	*sub;
	t_list	*node;

	len = (str_chr_closest(&str[i], "$\'\"") - &str[i]);
	sub = ft_substr(&str[i], 0, len);
	node = ft_lstnew(sub);
	ft_lstadd_back(tokens, node);
	return (len);
}

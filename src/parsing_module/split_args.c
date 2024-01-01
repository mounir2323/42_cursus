/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:33:24 by schibane          #+#    #+#             */
/*   Updated: 2023/12/07 19:51:37 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	quotes_case(char *str, unsigned int i)
{
	char	*c;
	int		len;

	c = ft_strchr(&str[i + 1], str[i]);
	len = (c - &str[i]) + 1;
	return (len);
}

char	*operator_case(char *str, unsigned int i)
{
	char	*word;
	int		len;

	len = 1;
	if (is_double_operator(str, i))
		len = 2;
	word = ft_substr(str, i, len);
	return (word);
}

char	*normal_case(char *str, unsigned int i)
{
	char	*word;
	int		len;

	len = 0;
	while (!is_word_limits(str, i + len))
	{
		if ((is_double_quote(str[i + len]) || is_single_quote(str[i + len])))
			len += quotes_case(str, i + len);
		else
			len ++;
	}
	word = ft_substr(str, i, len);
	return (word);
}

unsigned int	set_word_in_list(char *str, unsigned int i, t_list **lst)
{
	unsigned int	len;
	char			*word;
	t_list			*node;

	len = 0;
	word = NULL;
	if (is_operator(str[i]) || str[i] == '|')
		word = operator_case(str, i);
	else
		word = normal_case(str, i);
	node = ft_lstnew(word);
	ft_lstadd_back(lst, node);
	return (ft_strlen(word));
}

t_list	*split_args(char *str)
{
	t_list			*lst;
	unsigned int	i;

	i = 0;
	lst = NULL;
	while (str[i])
	{
		if (str[i] != ' ')
			i += set_word_in_list(str, i, &lst);
		else
			i ++;
	}
	return (lst);
}

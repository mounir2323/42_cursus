/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:17:19 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/17 01:03:36 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoinnn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest [i] = '\0';
	free(s1);
	return (dest);
}

char	*new_var(char *str)
{
	char	*new_var;

	new_var = ft_substr(str, 0, ft_strchr(str, '=') - str);
	return (new_var);
}

char	*del_coats(char *str)
{
	char	**dest;
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	dest = ft_split(str, '\"');
	i = 0;
	new_str = ft_strdup(dest[0]);
	while (i < ft_strlong(dest) - 1)
		new_str = ft_strjoinnn(new_str, dest[++i]);
	free_str_array(dest);
	return (new_str);
}

bool	ft_similar_var(char *str, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->variable, str))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:59:15 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/27 20:55:54 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pars_export(char *str)
{
	char	**dest;
	char	*pars;
	int		i;

	i = 0;
	dest = ft_split(str, '=');
	pars = ft_strdup (dest[0]);
	if (pars[0] != '_' && !ft_isalpha(pars[0]))
	{
		free_str_array(dest);
		return (pars);
	}
	while (pars[++i])
	{
		if (!ft_isalnum(pars[i]) && pars[i] != '_'
			&& pars[ft_strlen(pars) - 1] != '+')
		{
			free_str_array(dest);
			return (pars);
		}
	}
	free_str_array(dest);
	return (NULL);
}

int	export_print(t_env *head, int fd)
{
	t_env	*tmp;

	tmp = head;
	if (!head)
		return (2);
	while (tmp)
	{
		write(fd, "declare -x ", 11);
		write(fd, tmp->variable, ft_strlen(tmp->variable));
		write(fd, "=\"", 2);
		if (tmp->value)
			write(fd, tmp->value, ft_strlen(tmp->value));
		write(fd, "\"\n", 2);
		tmp = tmp->next;
	}
	return (0);
	return (0);
}

char	*export_join(t_env *env, char *str)
{
	t_env		*tmp;
	char		*tmp_value;
	char		*tmp_variable;
	char		**dest;
	char		*new_str;

	tmp = env;
	dest = ft_split(str, '+');
	tmp_variable = dest[0];
	tmp_value = ft_substr(str, ft_strchr(str, '=') - str + 1, ft_strlen(str)
			- ft_strlen(tmp_variable) - 1);
	while (tmp)
	{
		if (!ft_strcmp(tmp_variable, tmp->variable))
		{
			tmp->value = del_coats(ft_strjoinnn(tmp->value, tmp_value));
			return (NULL);
		}
		tmp = tmp->next;
	}
	new_str = ft_strjoin(tmp_variable, ft_strjoin("=", tmp_value));
	free(tmp_value);
	free_str_array(dest);
	return (new_str);
}

void	export_opt(t_config *config, char *str)
{
	char	*new_str;

	new_str = NULL;
	if (!ft_strchr(str, '=') && !ft_similar_var(str, config->env)
		&& !ft_similar_var(str, config->export_env))
		add_node_toenv(&config->export_env, str);
	if (ft_strchr(str, '='))
	{
		if (ft_strnstr(str, "+=", ft_strlen(str)))
		{
			export_join(config->env, str);
			new_str = export_join(config->export_env, str);
			if (new_str)
				add_both_env(config, del_coats(new_str));
		}
		else
			modify_value(str, config);
	}
}

int	export_cmd(t_config *config, char *str)
{
	if (str)
	{
		if (pars_export(str) != NULL)
			return (printf("export: %s : not a valid identifier\n",
					pars_export(str)), 2);
		else
		{
			export_opt(config, str);
			return (EXIT_SUCCESS);
		}
	}
	else
		return (2);
}

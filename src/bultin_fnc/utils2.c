/* ************************************************************************** */
/*		                                                                */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:40:34 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/10 20:10:04 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	add_node_toenv(t_env **head, char *str)
{
	char	**dest;
	t_env	*tmp;
	char	*first_value;

	*head = ft_add_node(*head, str);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	dest = ft_split(tmp->str, '=');
	tmp->variable = dest[0];
	first_value = ft_strchr(str, '=');
	if (first_value && tmp->value)
		tmp->value = del_coats(ft_strdup(++first_value));
	else
		loop_affect_var(tmp, dest);
}

void	add_to_env_from_export(t_config *config, char *str)
{
	char	*new;
	char	*schr;

	schr = ft_strchr(str, '=');
	new = new_var(str);
	if (!ft_similar_var(new, config->env) && ft_strlen(schr) > 1)
		add_node_toenv(&config->env, str);
}

void	add_both_env(t_config *config, char *str)
{
	char	*new;
	char	*schr;

	schr = ft_strchr(str, '=');
	new = new_var(str);
	if (!ft_similar_var(new, config->env) && ft_strlen(schr) > 1)
		add_node_toenv(&config->env, str);
	if (!ft_similar_var(new, config->export_env))
		add_node_toenv(&config->export_env, str);
}

void	modif(char *str, t_config *config, char *val, char *var)
{
	t_env	*tmp;
	t_env	*tmp_2;

	tmp = config->env;
	tmp_2 = config->export_env;
	add_to_env_from_export(config, str);
	while (tmp_2)
	{
		if (!ft_strcmp(tmp_2->variable, var))
		{
			tmp->value = del_coats(ft_strdup(val));
			tmp_2->value = del_coats(ft_strdup(val));
			break ;
		}
		if (tmp->next)
			tmp = tmp->next;
		tmp_2 = tmp_2->next;
	}
}

void	modify_value(char *str, t_config *config)
{
	char	*tem_variable;
	char	*tem_value;

	tem_variable = new_var(str);
	tem_value = ft_substr(str, ft_strchr(str, '=') - str + 1, ft_strlen(str)
			- ft_strlen(tem_variable) - 1);
	if (ft_similar_var(tem_variable, config->export_env))
		modif(str, config, tem_value, tem_variable);
	else
		add_both_env(config, str);
	free(tem_variable);
	free(tem_value);
}

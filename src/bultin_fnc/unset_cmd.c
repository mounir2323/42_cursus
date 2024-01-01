/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:03:43 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/26 19:28:02 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlong(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	free_node(t_env *node)
{
	if (!node)
		return ;
	if (node->str)
		free(node->str);
	if (node->variable)
		free(node->variable);
	if (node->value)
		free(node->value);
	free(node);
	node = NULL;
}

void	remove_node(t_env **head, char *str)
{
	t_env	*node;
	t_env	*prev_node;

	node = *head;
	prev_node = NULL;
	if (!node || ft_strlen(str) == 0)
		perror("unset :");
	else
	{
		while (node != NULL && ft_strcmp(node->variable, str) != 0)
		{
			prev_node = node;
			node = node->next;
		}
		if (node != NULL)
		{
			if (prev_node == NULL)
				*head = node->next;
			else
				prev_node->next = node->next;
			free_node(node);
		}
	}
}

int	unset_cmd(t_config *config, char *str)
{
	if (str == NULL || ft_strlen(str) == 0)
		return (2);
	else if (!ft_all_isalphanum(str))
	{
		printf(" minishell: unset: %s not a valid identifier\n", str);
		return (2);
	}
	remove_node(&config->env, str);
	remove_node(&config->export_env, str);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:34:31 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/25 21:07:26 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_node(char *str)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
	{
		perror("Erreur d'allocation");
		return (NULL);
	}
	node->str = ft_strdup(str);
	node->variable = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}

t_env	*ft_add_node(t_env *env, char *str)
{
	t_env	*tmp;

	if (env == NULL)
		env = new_node(str);
	else if (env)
	{
		tmp = env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node(str);
	}
	return (env);
}

void	loop_affect_var(t_env *node, char **dest)
{
	char	*temp;
	char	*del_co;
	int		lon;
	int		i;

	i = 1;
	lon = ft_strlong(dest);
	node->value = NULL;
	while (i < lon)
	{
		del_co = del_coats(dest[i]);
		temp = ft_strjoinnn(node->value, del_co);
		node->value = temp;
		free(del_co);
		i++;
	}
}

void	affect_vars(t_env *env)
{
	char	**dest;
	t_env	*node;

	node = env;
	while (node)
	{
		dest = NULL;
		if (ft_strchr(node->str, '='))
		{
			dest = ft_split(node->str, '=');
			node->variable = ft_strdup(dest[0]);
			loop_affect_var(node, dest);
			free_str_array(dest);
		}
		else
		{
			node->variable = ft_strdup(node->str);
			node->value = ft_strdup(node->str);
		}
		node = node->next;
	}
}

t_env	*ft_create_env(char **env)
{
	int		i;
	int		longe;
	t_env	*init;

	init = NULL;
	longe = ft_strlong(env);
	i = 0;
	while (i < longe)
	{
		init = ft_add_node(init, env[i]);
		i++;
	}
	affect_vars(init);
	return (init);
}

// void	ft_add_node_front(t_env **head, char *str)
// {
// 	t_env	*new_node;
// 	new_node = malloc(sizeof(t_env));
// 	if (!new_node)
// 	{
// 		perror("Error allocation");
// 		return ;
// 	}
// 	new_node->str = ft_strdup(str);
// 	new_node->next = *head;
// 	*head = new_node;
// }
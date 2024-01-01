/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:59:19 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 20:30:07 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_size(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**env_to_arrey(t_env *env)
{
	char	**dest;
	int		size;
	int		i;
	t_env	*tmp;

	tmp = env;
	size = env_size(env);
	i = 0;
	dest = malloc(sizeof(char *) * (size + 1));
	while (tmp)
	{
		dest[i] = ft_strjoin(tmp->variable, ft_strjoin("=", tmp->value));
		tmp = tmp->next;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**list_to_arrey(t_list *list)
{
	char	**dest;
	int		size;
	int		i;
	t_list	*tmp;

	size = ft_lstsize(list);
	i = 0;
	tmp = list;
	dest = malloc (sizeof(char *) * (size + 1));
	while (tmp)
	{
		dest[i] = (char *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

int	run_built_in(char **token, t_list *redir_list,
		t_list *inredir_list, t_config *config)
{
	int		fd;
	t_list	*tmp;
	t_redir	*redir;
	int		status;

	fd = 1;
	tmp = inredir_list;
	while (tmp)
	{
		redir = (t_redir *)tmp->content;
		fd = open_file_dispatcher(redir, config);
		tmp = tmp->next;
	}
	tmp = redir_list;
	while (tmp)
	{
		redir = (t_redir *)tmp->content;
		fd = open_file_dispatcher(redir, config);
		tmp = tmp->next;
	}
	status = execute_built_in_cmd(config, fd, token);
	return (status);
}

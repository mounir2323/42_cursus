/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:39 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 20:27:46 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		free_node(tmp);
		tmp = tmp->next;
	}
}

void	free_redir(void *rdir_lst)
{
	t_redir	*redir_list;

	redir_list = (t_redir *)rdir_lst;
	ft_free(redir_list->path_file);
	if (redir_list->fd != 0)
		close(redir_list->fd);
}

void	free_commands_list(void *cmd_list)
{
	t_command	*comande_list;

	comande_list = (t_command *)cmd_list;
	ft_free(comande_list->name);
	ft_lstclear(&comande_list->args_list, free);
	ft_free(comande_list->path);
	ft_lstclear(&comande_list->in_redir_list, free_redir);
	ft_lstclear(&comande_list->out_redir_list, free_redir);
}

void	free_config(t_config *config, bool a)
{
	ft_lstclear(&config->inputs_list, free);
	ft_lstclear(&config->commands_list, free_commands_list);
	if (a == true)
	{
		free_env(config->env);
		free_env(config->export_env);
		ft_free(config);
	}
}

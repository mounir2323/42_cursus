/* ************************************************************************** */
/*                                                                        */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:20:57 by mtayebi           #+#    #+#             */
/*   Updated: 2023/11/25 18:00:49 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_with_opt(t_list *args_list, int fd)
{
	char		*dest;
	t_list		*tmp;

	tmp = args_list->next;
	while (((char *)tmp->next) != NULL)
	{
		dest = ft_strdup((char *)tmp->next->content);
		ft_putstr_fd(dest, fd);
		if (tmp->next->next)
			write (fd, " ", 1);
		free(dest);
		tmp = tmp->next;
	}
}

void	echo_without_opt(t_list *args_list, int fd)
{
	char		*dest;
	t_list		*tmp;
	t_list		*prev;

	tmp = args_list->next;
	prev = args_list;
	while ((tmp))
	{
		dest = ft_strdup((char *)tmp->content);
		ft_putstr_fd(dest, fd);
		if (tmp->next)
			write (fd, " ", 1);
		free(dest);
		prev = prev->next;
		tmp = tmp->next;
	}
	if (ft_strcmp((char *)prev->content, "\n"))
		write(fd, "\n", 1);
}

int	echo_cmd(t_config *conf, int fd, char **token)
{
	t_command	*comm;
	t_list		*args_list;

	comm = (t_command *)conf->commands_list->content;
	args_list = comm->args_list;
	if (!token[1])
	{
		printf("\n");
		return (0);
	}
	else if (!ft_strcmp((char *)args_list->next->content, "-n"))
	{
		echo_with_opt(args_list, fd);
		return (EXIT_SUCCESS);
	}
	else
	{
		echo_without_opt(args_list, fd);
		return (EXIT_SUCCESS);
	}
	return (printf("%s\n: command not found",
			(char *)args_list->content), 2);
}

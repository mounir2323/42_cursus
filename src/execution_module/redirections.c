/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:30 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 20:31:29 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file_dispatcher(t_redir *redir, t_config *config)
{
	if (redir->type == INPUT_REDIR)
		redir->fd = open(redir->path_file, O_RDONLY);
	else if (redir->type == OUTPUT_REDIR)
	{
		unlink(redir->path_file);
		redir->fd = open(redir->path_file, O_CREAT | O_EXCL | O_WRONLY, 0666);
	}
	else if (redir->type == OUTPUT_APPEND)
		redir->fd = open(redir->path_file, O_APPEND | O_CREAT | O_WRONLY, 0666);
	else
		redir->fd = heredoc_input(redir, config);
	return (redir->fd);
}

void	dup_loop(t_list	*tmp, t_config *config, int STD)
{
	int		fd;
	t_redir	*redir;

	while (tmp)
	{
		redir = (t_redir *)tmp->content;
		fd = open_file_dispatcher(redir, config);
		if (fd < 0)
			return (printf("minishell: %s: No such file or directory\n",
					redir->path_file), exit(EXIT_FAILURE));
		if (!tmp->next)
			dup2(fd, STD);
		tmp = tmp->next;
	}
}

void	dup_input_redir(t_command *command, int prev_pipe[2], t_config *config)
{
	t_list	*tmp;

	tmp = command->in_redir_list;
	if (command->in_redir_list)
		dup_loop(tmp, config, STDIN_FILENO);
	else if (prev_pipe && command->nbr != 1)
	{
		close(prev_pipe[WRITE_END]);
		dup2(prev_pipe[READ_END], STDIN_FILENO);
		close(prev_pipe[READ_END]);
	}
	else
		return ;
}

void	dup_output_redir(t_command *command, int next_pipe[2],
		unsigned int size, t_config *config)
{
	t_list	*tmp;

	tmp = command->out_redir_list;
	if (command->out_redir_list)
		dup_loop(tmp, config, STDOUT_FILENO);
	else if (next_pipe && command->nbr != size)
	{
		close(next_pipe[READ_END]);
		dup2(next_pipe[WRITE_END], STDOUT_FILENO);
		close(next_pipe[WRITE_END]);
	}
	else
		return ;
}

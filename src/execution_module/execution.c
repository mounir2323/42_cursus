/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:37:34 by schibane          #+#    #+#             */
/*   Updated: 2023/12/25 20:52:27 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_path_validty(t_config *config, t_command *command)
{
	char	**env;

	env = env_to_arrey(config->env);
	command->path = get_command_path(env,
			(char *)command->args_list->content);
	if (!command->path || access(command->path, F_OK) == -1)
		return (printf("minishell: %s: Command not found\n",
				(char *)command->args_list->content), exit(EXIT_NOT_FOUND));
	if (access(command->path, X_OK) == -1)
		return (printf("minishell: %s: Permission denied\n",
				(char *)command->args_list->content), exit(EXIT_PERMIS_DENIED));
}

void	run_execve(t_config *config, t_command *command, char **args)
{
	char	**env;

	check_path_validty(config, command);
	env = env_to_arrey(config->env);
	execve(command->path, args, env);
	printf("Command failed\n");
	exit(EXIT_FAILURE);
}

void	execute_command(t_config *config, t_command *command, \
	int prev_pipe[2], int next_pipe[2])
{
	char	**args;
	int		status_built;

	args = list_to_arrey(command->args_list);
	status_built = 0;
	if (!prev_pipe && !next_pipe && is_bultins(args))
		status_built = run_built_in(args, command->out_redir_list,
				command->in_redir_list, config);
	command->id = fork();
	if (command->id == 0)
	{
		if (!prev_pipe && !next_pipe && is_bultins(args))
			exit(status_built);
		dup_input_redir(command, prev_pipe, config);
		dup_output_redir(command, next_pipe,
			ft_lstsize(config->commands_list), config);
		if (is_bultins(args))
		{
			status_built = execute_built_in_cmd(config, 1, args);
			exit(status_built);
		}
		run_execve(config, command, args);
	}
}

void	chain_piped_commands(t_list *commands_list, t_config *config)
{
	t_list		*tmp;
	t_command	*command;
	int			prev_pipe[2];
	int			next_pipe[2];

	tmp = commands_list;
	pipe(prev_pipe);
	while (tmp)
	{
		command = (t_command *)tmp->content;
		if (tmp->next)
			pipe(next_pipe);
		execute_command(config, command, prev_pipe, next_pipe);
		close(prev_pipe[READ_END]);
		close(prev_pipe[WRITE_END]);
		if (tmp->next)
		{
			prev_pipe[READ_END] = next_pipe[READ_END];
			prev_pipe[WRITE_END] = next_pipe[WRITE_END];
		}
		tmp = tmp->next;
	}
}

void	execution(t_list *commands_list, t_config *config)
{
	unsigned int	count;
	t_list			*tmp;
	t_command		*com;
	int				status;

	count = (unsigned int) ft_lstsize(commands_list);
	tmp = commands_list;
	if (count < 2)
	{
		execute_command(config, commands_list->content, NULL, NULL);
		wait(&status);
		config->status_code = WEXITSTATUS(status);
		return ;
	}
	chain_piped_commands(commands_list, config);
	while (tmp)
	{
		com = tmp->content;
		if (com->nbr == count)
			waitpid(com->id, &status, 0);
		else
			waitpid(com->id, NULL, 0);
		tmp = tmp->next;
	}
	config->status_code = WEXITSTATUS(status);
}

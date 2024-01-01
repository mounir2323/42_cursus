/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:13:45 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 20:28:31 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_config	*config;
	bool		correct_redir;

	if (argc != 1)
		return (EXIT_FAILURE);
	argv = NULL;
	config = init_config(env);
	sig();
	while (true)
	{
		config->inputs_list = parsing_arguments();
		if (config->inputs_list)
		{
			config->commands_list = lexing_input(config->inputs_list);
			ft_lstclear(&config->inputs_list, free);
			correct_redir = expansion(config->commands_list, config);
			if (correct_redir)
				execution(config->commands_list, config);
			else
				config->status_code = 1;
			free_config (config, false);
		}
	}
	return (EXIT_SUCCESS);
}

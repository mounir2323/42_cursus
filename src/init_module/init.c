/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:37:38 by schibane          #+#    #+#             */
/*   Updated: 2023/12/26 20:27:43 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_config	*init_config(char **env)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	config->env = ft_create_env(env);
	config->export_env = ft_create_env(env);
	config->commands_list = NULL;
	config->status_code = 0;
	return (config);
}

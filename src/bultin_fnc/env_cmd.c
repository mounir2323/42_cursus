/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:05:20 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/21 22:00:59 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_cmd(t_config *config, int fd, char **token)
{
	t_env	*tmp;

	if (config->env == NULL)
	{
		perror("error env");
		return (2);
	}
	else if (token[1])
	{
		printf ("env: %s: No such file or directory\n", token[1]);
		return (2);
	}
	tmp = config->env;
	while (tmp)
	{
		write(fd, tmp->variable, ft_strlen(tmp->variable));
		write(fd, "=", 1);
		write(fd, tmp->value, ft_strlen(tmp->value));
		write(fd, "\n", 1);
		tmp = tmp->next;
	}
	return (0);
}

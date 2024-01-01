/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:38:01 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/26 21:41:07 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_all_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
			return (false);
	return (true);
}

int	exit_cmd(char **token, t_config *config)
{
	if (ft_strlong(token) > 2)
		return (printf("exit: too many arguments\n"), 0);
	else if (!token[1] || ft_strlen(token[1]) == 0)
	{
		free_config(config, true);
		exit(EXIT_SUCCESS);
	}
	else if (ft_all_isdigit(token [1]))
	{
		free_config(config, true);
		exit(ft_atoi(token[1]));
	}
	else
	{
		printf("exit: %s: numeric argument required\n", token[1]);
		free_config(config, true);
		exit(2);
	}
}

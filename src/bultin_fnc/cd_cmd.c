/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:57:15 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/22 18:23:06 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_cmd(char **token, int fd)
{
	char	*home;

	home = getenv("HOME");
	if (token[1] == NULL)
	{
		chdir(home);
		return (0);
	}
	else if (ft_strlen(token[1]) == 0)
	{
		chdir(home);
		return (0);
	}
	else if (opendir(token[1]) != NULL)
	{
		chdir(token[1]);
		return (0);
	}
	else
	{
		ft_putstr_fd("cd: ", fd);
		perror(token[1]);
		return (2);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:25:46 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/22 18:25:11 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_cmd(int fd)
{
	char	buf[1024];
	char	*dir;

	dir = getcwd(buf, 1024);
	if (!dir)
	{
		perror("pwd :");
		return (2);
	}
	write(fd, dir, ft_strlen(dir));
	write(fd, "\n", 1);
	return (0);
}

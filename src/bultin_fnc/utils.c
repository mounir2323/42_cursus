/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:57:08 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/27 20:33:12 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_arreycpy(char **mat)
{
	int		i;
	int		j;
	char	**dest;

	dest = malloc((ft_strlong(mat) + 1) * (sizeof(char *)));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (mat[i])
	{
		dest[j] = ft_strdup(mat[i]);
		i++;
		j++;
	}
	dest[j] = NULL;
	return (dest);
}

void	free_str_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

bool	is_bultins(char **token)
{
	if (!token[0])
		return (false);
	if (!ft_strcmp(token[0], "env"))
		return (true);
	else if (!ft_strcmp(token[0], "pwd"))
		return (true);
	else if (!ft_strcmp(token[0], "export"))
		return (true);
	else if (!ft_strcmp(token[0], "exit"))
		return (true);
	else if (!ft_strcmp(token[0], "unset"))
		return (true);
	else if (!ft_strcmp(token[0], "cd"))
		return (true);
	else if (!ft_strcmp(token[0], "echo"))
		return (true);
	return (false);
}

void	export(t_config *config, int fd, char **token, int status)
{
	int	i;

	i = 0;
	if (!token[1])
		status = export_print(config->export_env, fd);
	while (i < ft_strlong(token))
		status = export_cmd(config, token[++i]);
}

int	execute_built_in_cmd(t_config *config, int fd, char **token)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (!ft_strcmp(token[0], "env"))
		status = env_cmd(config, fd, token);
	else if (!ft_strcmp(token[0], "pwd"))
		status = pwd_cmd(fd);
	else if (!ft_strcmp(token[0], "export"))
		export(config, fd, token, status);
	else if (!ft_strcmp(token[0], "exit"))
		status = exit_cmd(token, config);
	else if (!ft_strcmp(token[0], "unset"))
		while (i < ft_strlong(token))
			status = unset_cmd(config, token[++i]);
	else if (!ft_strcmp(token[0], "cd"))
		status = cd_cmd(token, fd);
	else if (!ft_strcmp(token[0], "echo"))
		status = echo_cmd(config, fd, token);
	return (status);
}

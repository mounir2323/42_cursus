/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commnd_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:40:03 by schibane          #+#    #+#             */
/*   Updated: 2023/12/25 21:57:57 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_path_index(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
			return (i);
		i ++;
	}
	return (-1);
}

char	**get_path_array(char **env, unsigned int index)
{
	char	**path_array;
	char	*first_path;

	path_array = ft_split(env[index], ':');
	first_path = ft_substr(path_array[0], 5, ft_strlen(path_array[0]));
	free(path_array[0]);
	path_array[0] = first_path;
	return (path_array);
}

char	*make_try_path(char *first_arg, char *pathenv)
{
	char	*try_path;
	char	*tmp;

	tmp = ft_strjoin("/", first_arg);
	try_path = ft_strjoin(pathenv, tmp);
	free(tmp);
	return (try_path);
}

char	*get_command_path(char **env, char *first_arg)
{
	unsigned int	i;
	char			*try_path;
	char			**path_array;
	int				result;
	int				path_index;

	i = 0;
	if (ft_strchr(first_arg, '/'))
		return (ft_strdup(first_arg));
	path_index = get_path_index(env);
	if (path_index < 0)
		return (NULL);
	path_array = get_path_array(env, path_index);
	while (path_array[i])
	{
		try_path = make_try_path(first_arg, path_array[i]);
		result = access(try_path, F_OK);
		if (result > -1)
			return (try_path);
		free(try_path);
		i ++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:20:37 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 20:27:34 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_file(const char *baseFilename, int *fd)
{
	char	*filename;
	int		index;
	char	*indexto_str;

	filename = NULL;
	index = 1;
	while (true)
	{
		indexto_str = ft_itoa(index);
		filename = ft_strjoin(baseFilename, indexto_str);
		*fd = open (filename, O_CREAT | O_EXCL
				| O_RDWR, 0666);
		free(indexto_str);
		if (*fd >= 0)
			break ;
		index ++;
	}
	return (filename);
}

unsigned int	replace_dollar_heredoc(int fd, char *str, t_config *config)
{
	unsigned int	len;
	char			*sub;
	char			*value;

	len = str_chr_closest(str + 1, "\" $\'") - (str);
	if (len == 0)
		return (1);
	sub = ft_substr(str + 1, 0, len - 1);
	value = get_variable_value(sub, config);
	if (!value)
		return (free(sub), len);
	write(fd, value, ft_strlen(value));
	free(value);
	free(sub);
	return (len);
}

void	write_line(int fd, char *line, t_config *config)
{
	unsigned int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
			i += replace_dollar_heredoc(fd, &line[i], config);
		else
		{
			write(fd, &line[i], 1);
			i ++;
		}
	}
}

char	*del_s_coats(char *str)
{
	char	**dest;
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	dest = ft_split(str, '\'');
	i = 0;
	new_str = ft_strdup(dest[0]);
	while (i < ft_strlong(dest) - 1)
		new_str = ft_strjoinnn(new_str, dest[++i]);
	free_str_array(dest);
	free(str);
	return (new_str);
}

int	heredoc_input(t_redir *redir, t_config *config)
{
	char	*line;
	char	*filename;
	char	*stop;
	int		fd;

	filename = create_file("/tmp/here_doc_", &fd);
	stop = del_coats(redir->path_file);
	stop = del_s_coats(stop);
	line = readline("> ");
	while (ft_strcmp(stop, line))
	{
		if (line)
		{
			if (!ft_strchr(redir->path_file, '\"'))
				write_line(fd, line, config);
			else
				write(fd, line, ft_strlen(line));
		}
		write(fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	return (free(stop), free(line), free(filename), fd);
}

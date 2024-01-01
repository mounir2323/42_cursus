/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:56:50 by schibane          #+#    #+#             */
/*   Updated: 2023/12/26 21:57:09 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H
# include "../libft/libft.h"

typedef enum e_redir_type {
	OUTPUT_REDIR = 0,
	OUTPUT_APPEND = 1,
	INPUT_REDIR = 2,
	HERE_DOC = 3
}	t_redir_type;

typedef struct s_redir
{
	char			*path_file;
	t_redir_type	type;
	int				fd;
}	t_redir;

typedef struct s_command
{
	char			*name;
	t_list			*args_list;
	unsigned int	nbr;
	char			*path;
	t_list			*out_redir_list;
	t_list			*in_redir_list;
	pid_t			id;
}	t_command;

unsigned int	count_comands(t_list *lst_input);
t_command		*create_command(unsigned int i);
bool			is_redir_operator(char *str);
void			add_redirection_list(t_list **redir_list,
					char *path, t_redir_type type);
t_redir			*create_redirection(char *path, t_redir_type type);
void			print_command_list(t_list *command_list);

#endif
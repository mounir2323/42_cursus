/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:14:33 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 21:03:57 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <dirent.h>
# include <readline/readline.h>
# include <signal.h>
# include "parsing.h"
# include "../libft/libft.h"
# include "builtins.h"
# include "execution.h"
# include "lexing.h"
# include "expention.h"
# include "structs.h"

struct sigaction	g_sign;

t_list		*parsing_arguments(void);
t_config	*init_config(char **env);
t_list		*lexing_input(t_list *lst_input);
bool		expansion(t_list *command_list, t_config *config);
void		execution(t_list *commands_list, t_config *config);
void		affect_vars(t_env *env);
void		loop_affect_variable(t_env *env);
char		**list_to_arrey(t_list *list);
char		**env_to_arrey(t_env *env);
int			env_size(t_env *env);
void		ft_prin_lst(t_env *env);
void		print_lst(t_list *lst);
int			open_file_dispatcher(t_redir *redir, t_config *config);
void		dup_input_redir(t_command *command, int prev_pipe[2],
				t_config *config);
void		dup_output_redir(t_command *command, int next_pipe[2],
				unsigned int size, t_config *config);
void		sig(void);
int			heredoc_input(t_redir *redir, t_config *config);
char		*get_next_line(int fd);
int			run_built_in(char **token, t_list *redir_list,
				t_list *inredir_list, t_config *config);
void		ft_free(void *ptr);
void		free_config(t_config *config, bool a);

#endif
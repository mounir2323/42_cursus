/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:31:56 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/27 21:01:43 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <dirent.h>
# include <readline/readline.h>
# include "../libft/libft.h"
# include "structs.h"

int			ft_strlong(char **map);
void		free_str_array(char **str);
char		**ft_arreycpy(char **mat);
void		add_node_toenv(t_env **head, char *str);
bool		ft_similar_var(char *str, t_env *env);
void		add_both_env(t_config *config, char *str);
void		modify_value(char *str, t_config *config);
int			execute_built_in_cmd(t_config *config, int fd, char **token);
int			export_print(t_env *head, int fd);
char		*del_coats(char *str);
void		loop_affect_var(t_env *node, char **dest);
void		affect_vars(t_env *env);
char		*ft_strjoinnn(char *s1, char *s2);
char		*new_var(char *str);
int			export_print(t_env *head, int fd);
int			unset_cmd(t_config *config, char *str);
int			pwd_cmd(int fd);
int			export_cmd(t_config *config, char *str);
int			cd_cmd(char **input, int fd);
int			exit_cmd(char **token, t_config *config);
int			env_cmd(t_config *config, int fd, char **token);
int			echo_cmd(t_config *conf, int fd, char **token);
bool		is_bultins(char **token);
void		free_node(t_env *node);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:06:30 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/26 20:37:02 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_env
{
	char			*str;
	char			*variable;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_config
{
	t_list	*inputs_list;
	t_env	*env;
	t_env	*export_env;
	t_list	*commands_list;
	int		status_code;
}			t_config;

t_env		*ft_create_env_export(char **env, t_config *init);
t_env		*ft_create_env(char **env);
t_env		*new_node(char *str);
t_env		*ft_add_node(t_env *env, char *str);
char		*get_variable_value(char *str, t_config *config);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expention.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:20:25 by schibane          #+#    #+#             */
/*   Updated: 2023/12/20 18:25:30 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPENTION_H
# define EXPENTION_H

unsigned int	replace_dollar_sign(char *str, int i,
					t_list **tokens, t_config *config);
unsigned int	skip_quotes(char *str, int i, t_list **tokens);
unsigned int	copy_until_limit(char *str, int i, t_list **tokens);
unsigned int	handle_dollar_indouble_q(char *str, int i,
					t_list **token, t_config *config);
char			*str_chr_closest(char *str, char *delimiteurs);
void			normal_add(char *str, t_list **result, int index);
void			trim_quotes_add(char *str, t_list **result, int i);
void			get_result_args(t_list *tokens, t_list **result);
t_list			*tokenize(char *str, t_config *config);
bool			expend_redirs(t_command *command, t_config *config);
void			trim_s_quotes_add(char *str, t_list **result, int i);

#endif
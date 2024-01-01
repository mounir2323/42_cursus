/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:33:57 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 21:04:48 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

t_list			*split_args(char *str);
bool			is_word_start(char *str, unsigned int i);
bool			is_double_operator(char *str, unsigned int i);
bool			is_operator(char c);
bool			is_single_quote(char c);
bool			is_double_quote(char c);
bool			is_word_limits(char *str, unsigned int i);
bool			is_missing_quotes(char *str);
bool			is_syntax_error(t_list *lst);

#endif
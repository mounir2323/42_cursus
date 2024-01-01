/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:39:05 by schibane          #+#    #+#             */
/*   Updated: 2023/12/08 16:01:40 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include <fcntl.h>
# define EXIT_NOT_FOUND 127
# define EXIT_PERMIS_DENIED 126
# define READ_END 0
# define WRITE_END 1

char	*get_command_path(char **env, char *first_arg);

#endif
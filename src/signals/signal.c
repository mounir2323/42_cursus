/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:32:46 by mtayebi           #+#    #+#             */
/*   Updated: 2023/12/27 21:04:29 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_int_eof(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
		exit(EXIT_SUCCESS);
}

void	sig(void)
{
	rl_catch_signals = 0;
	g_sign.sa_handler = signal_int_eof;
	sigaction(SIGINT, &g_sign, NULL);
	sigaction(SIGQUIT, &g_sign, NULL);
	rl_clear_signals();
}

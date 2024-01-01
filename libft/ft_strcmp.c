/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:15:06 by schibane          #+#    #+#             */
/*   Updated: 2023/12/11 21:56:50 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		r;

	i = 0;
	r = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (!((s1[i] == 0) && (s2[i] == 0)))
	{
		if (s1[i] != s2[i])
		{
			r = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (r);
		}
		i ++;
	}
	return (r);
}

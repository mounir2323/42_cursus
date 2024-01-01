/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:22:45 by schibane          #+#    #+#             */
/*   Updated: 2023/03/23 15:14:49 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = 0;
	while (i < (int) n)
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i ++;
	}
	return (NULL);
}

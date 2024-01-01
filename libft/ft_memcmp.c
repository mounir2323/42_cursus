/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:41:45 by schibane          #+#    #+#             */
/*   Updated: 2023/03/23 18:59:47 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;
	int		r;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	r = 0;
	while ((i < n))
	{
		if (str1[i] != str2[i])
		{
			r = (unsigned char)str1[i] - (unsigned char)str2[i];
			return (r);
		}
		i ++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:33:15 by schibane          #+#    #+#             */
/*   Updated: 2023/03/22 15:13:37 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	cha;

	str = (char *)s;
	cha = (char)c;
	while (*str != 0)
	{
		if (*str == cha)
			return (str);
		str++;
	}
	if (cha == 0)
		return (str);
	return (NULL);
}

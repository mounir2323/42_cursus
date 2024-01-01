/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:55:03 by schibane          #+#    #+#             */
/*   Updated: 2023/03/22 12:19:03 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	i;

	len = (int) ft_strlen(s);
	i = len - 1;
	c = (char)c;
	if (c == 0)
		return ((char *)&s[len]);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i --;
	}
	return (NULL);
}

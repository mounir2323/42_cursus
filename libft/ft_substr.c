/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:49:57 by schibane          #+#    #+#             */
/*   Updated: 2023/03/25 14:45:56 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return ((char *) ft_calloc(1, 1));
	if (len > len_s - (unsigned int)start)
		len = len_s - (unsigned int)start;
	str = (char *) ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

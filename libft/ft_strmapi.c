/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:53:01 by schibane          #+#    #+#             */
/*   Updated: 2023/03/27 17:04:41 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		s_len;
	char		*str;

	i = 0;
	s_len = ft_strlen(s);
	str = (char *)ft_calloc(s_len + 1, 1);
	if (!str)
		return (NULL);
	while (i < s_len)
	{
		str[i] = (*f)((unsigned int)i, s[i]);
		i ++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:53:03 by schibane          #+#    #+#             */
/*   Updated: 2023/03/24 16:10:30 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		need_len;

	j = 0;
	i = 0;
	need_len = (int)ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while ((size_t)j <= len)
	{
		if (i == need_len)
			return ((char *)&haystack[j - i]);
		if (haystack[j] == 0)
			return (NULL);
		if (needle[i] == haystack[j])
			i ++;
		else
		{
			j = j - i;
			i = 0;
		}
		j ++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:34:40 by schibane          #+#    #+#             */
/*   Updated: 2023/12/27 20:59:53 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findstart(char const *s1, char const *set)
{
	int	set_len;
	int	start;
	int	j;

	j = 0;
	start = 0;
	set_len = ft_strlen(set);
	while (s1[start] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[start] == set[j])
				break ;
			else
				j ++;
		}
		if (j == set_len)
			break ;
		start ++;
	}
	return (start);
}

static	int	ft_findend(char const *s1, char const *set)
{
	int		j;
	int		end;
	int		set_len;

	end = ft_strlen(s1) - 1;
	set_len = ft_strlen(set);
	while (end >= 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[end] == set[j])
				break ;
			else
				j ++;
		}
		if (j == set_len)
			break ;
		end --;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = ft_findstart(s1, set);
	end = ft_findend(s1, set);
	if (end < start)
		return ((char *)ft_calloc(1, 1));
	str = (char *)ft_calloc(end - start + 2, 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}

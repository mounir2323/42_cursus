/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:41:46 by schibane          #+#    #+#             */
/*   Updated: 2023/03/25 13:50:56 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	len = ft_strlen(s1);
	cpy = (char *)ft_calloc(len + 1, 1);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, len + 1);
	return (cpy);
}

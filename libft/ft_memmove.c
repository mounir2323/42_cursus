/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:33:15 by schibane          #+#    #+#             */
/*   Updated: 2023/03/30 13:37:57 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;
	int		i;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else if (dst > src)
	{
		src2 = (char *)src;
		dst2 = (char *)dst;
		i = (int)(len - 1);
		while (i >= 0)
		{
			dst2[i] = src2[i];
			i --;
		}
		return (dst);
	}
	else
		return (dst);
}

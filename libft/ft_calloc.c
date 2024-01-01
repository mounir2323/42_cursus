/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:08:16 by schibane          #+#    #+#             */
/*   Updated: 2023/03/24 23:39:06 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc((count * size));
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:31:42 by schibane          #+#    #+#             */
/*   Updated: 2023/03/30 14:28:31 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_calculnbrlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

static	void	ft_copynumstocharrev(int addminus,
	char *str, int n, int str_len)
{
	int	i;

	i = str_len - 2;
	while (i >= 0 + addminus)
	{
		str[i] = (n % 10) + ('0');
		n /= 10;
		i --;
	}
}

static	char	*ft_handleexceptions(int n, char *str)
{
	if (n == -2147483648)
	{
		str = (char *)ft_calloc(12, 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	else if (n == 0)
	{
		str = (char *)ft_calloc(2, 1);
		if (!str)
			return (NULL);
		str[0] = '0';
		return (str);
	}
	else
		return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				addminus;
	int				num_len;
	int				str_len;

	str = NULL;
	num_len = ft_calculnbrlen(n);
	addminus = 0;
	if (n == 0 || n == -2147483648)
		return (ft_handleexceptions(n, str));
	else if (n < 0)
	{
		addminus = 1;
		n *= -1;
	}
	str_len = num_len + 1 + addminus;
	str = (char *)ft_calloc(str_len, 1);
	if (!str)
		return (NULL);
	if (addminus == 1)
		str[0] = '-';
	ft_copynumstocharrev(addminus, str, n, str_len);
	return (str);
}

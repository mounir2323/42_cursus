/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schibane <schibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:10:31 by schibane          #+#    #+#             */
/*   Updated: 2023/10/16 01:01:30 by schibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (((s[i] != c) && i == 0) || ((s[i] != c) && (s[i - 1] == c)))
			count ++;
		i ++;
	}
	return (count);
}

static int	ft_countwordlen(char *s, char c)
{
	int	j;

	j = 0;
	while ((s[j] != '\0') && (s[j] != c))
		j ++;
	return (j);
}

static int	ft_copystringsintab(char *str, char c, int tab_len, char **tab)
{
	int		i;
	int		word_len;

	i = 0;
	while (*str)
	{
		if (*str != c && i < tab_len)
		{
			word_len = ft_countwordlen(str, c);
			tab[i] = (char *) malloc(word_len + 1);
			if (!tab[i])
			{
				while (--i >= 0)
					free(tab[i]);
				free(tab);
				return (0);
			}
			ft_strlcpy(tab[i], str, word_len + 1);
			i ++;
			str += (word_len - 1);
		}
		str ++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		tab_len;
	char	*str;
	int		successalloc;

	str = (char *)s;
	tab_len = ft_countwords(s, c);
	if (!tab_len)
		return ((char **)ft_calloc(1, sizeof(char *)));
	tab = (char **) ft_calloc((tab_len + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	successalloc = ft_copystringsintab(str, c, tab_len, tab);
	if (successalloc)
		tab[tab_len] = NULL;
	else
		return (NULL);
	return (tab);
}

// #include "libft.h"

// int	wortcounter(char const *s, char c)
// {
// 	int	i;
// 	int	strcounter;

// 	i = 0;
// 	strcounter = 0;
// 	while (s[i] == c)
// 		i++;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == c && s[i - 1] != c)
// 			strcounter++;
// 		i++;
// 	}
// 	if (i > 0 && s[i - 1] != c)
// 		strcounter++;
// 	if (s[0] == '\0')
// 		strcounter = 0;
// 	return (strcounter);
// }

// int	stringmake(int wortcount, char const *s, char c, char	**newarray)
// {
// 	int	i;
// 	int	a;
// 	int	j;
// 	int	charcount;

// 	i = 0;
// 	j = 0;
// 	while (i < wortcount)
// 	{
// 		charcount = 0;
// 		while (s[j] == c && s[j])
// 			j++;
// 		while (s[j + charcount] != c && s[j + charcount] != '\0')
// 			charcount++;
// 		newarray[i] = (char *)ft_calloc(charcount + 1, (sizeof(char)));
// 		if (newarray[i] == NULL)
// 		{
// 			while (i > 0)
// 			{
// 			free (newarray[i - 1]);
// 			i--;
// 			}
// 			free (newarray);
// 			return (0);
// 		}
// 		a = 0;
// 		while (charcount > a && s[j])
// 			newarray[i][a++] = s[j++];
// 		i++;
// 	}
// 	return (1);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		wortcount;
// 	char	**newarray;

// 	if (s == NULL)
// 		return (NULL);
// 	wortcount = wortcounter(s, c);
// 	// printf("wc = %d\n", wortcount);
// 	newarray = (char **)ft_calloc(wortcount + 1, (sizeof(char *)));
// 	// if (s[0] == 0)
// 	// {
// 	// 	newarray[0] = 0;
// 	// 	return (newarray);
// 	// }
// 	if (newarray == NULL)
// 		return (NULL);
// 	if (stringmake(wortcount, s, c, newarray) == 0)
// 		return (0);
// 	// newarray[wortcount] = NULL;
// 	return (newarray);
// }

//  int main(void)
// {
//     char **tab;
//     int i;
//     i = 0;
//     tab = ft_split("ppp\0", 0);
//     while (tab[i])
//     {
//         printf("%s\n", tab[i]);
//         i++;
//     }
// 	printf("%s\n", tab[i]);
// }

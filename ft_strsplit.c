/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:06:53 by bsatou            #+#    #+#             */
/*   Updated: 2020/02/29 16:49:28 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_len_word(char const *s, size_t k, char c)
{
	size_t	len;

	len = ft_count_letters(ft_strsub(s, k, ft_strlen(s) - k), c);
	return (len);
}

static void		ft_strsplit_clear(char **tab, size_t i)
{
	while ((int)i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	k;

	i = -1;
	k = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * \
	(ft_count_words(s, c) + 1))))
		return (NULL);
	while (++i < (int)ft_count_words(s, c))
	{
		while (s[k] == c && s[k])
			k++;
		if (!(tab[i] = ft_strnew((ft_len_word(s, k, c)))))
		{
			ft_strsplit_clear(tab, i);
			return (NULL);
		}
		tab[i] = ft_strsub(s, k, ft_len_word(s, k, c));
		while (s[k] != c && s[k])
			k++;
	}
	tab[i] = NULL;
	return (tab);
}

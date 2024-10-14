/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:16:56 by leaugust          #+#    #+#             */
/*   Updated: 2024/05/22 17:52:01 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

static int	ft_word_count(char const *s1, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			i++;
		else
		{
			count++;
			while (s1[i] && s1[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_word(const char *str, int *index, char c)
{
	int		i;
	size_t	word_len;
	char	*cpy;

	word_len = 0;
	while (str[*index] && str[*index] == c)
		(*index)++;
	i = *index;
	while (str[i] && str[i] != c)
	{
		word_len++;
		i++;
	}
	cpy = (char *)malloc(sizeof(char) * (word_len + 1));
	if (cpy == 0)
		return (0);
	i = 0;
	while (str[*index] && str[*index] != c)
		cpy[i++] = str[(*index)++];
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wc;
	int		index;
	char	**tab;

	wc = ft_word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (tab == 0)
		return (0);
	i = 0;
	index = 0;
	while (i < wc)
	{
		tab[i] = ft_word(s, &index, c);
		if (tab[i] == 0)
			return (malloc_error(tab));
		i++;
	}
	tab[i] = 0;
	return (tab);
}

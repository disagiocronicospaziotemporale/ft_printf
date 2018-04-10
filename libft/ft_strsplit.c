/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:19:58 by mriccard          #+#    #+#             */
/*   Updated: 2017/12/01 19:06:09 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*fill_arr(char const *s, char c, int *i)
{
	char			*str;
	int				j;
	unsigned int	len;

	len = 0;
	while (s[(*i) + len] != c && s[(*i) + len])
		len++;
	if ((str = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		str[j] = s[*i];
		j++;
		*i = *i + 1;
	}
	str[j] = 0;
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	return (str);
}

static int			count_words(char const *s, char c)
{
	int				i;

	if (s[0] == 0)
		return (0);
	i = 1;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			i++;
		s++;
	}
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	int				nb_words;
	int				i;
	int				j;
	char			**arr;

	if (s == NULL)
		return (NULL);
	nb_words = count_words(s, c);
	if ((arr = (char **)malloc(sizeof(char *) * (nb_words + 2))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	j = 0;
	while (j < nb_words && s[i])
	{
		arr[j] = fill_arr(s, c, &i);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

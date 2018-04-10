/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:57:21 by mriccard          #+#    #+#             */
/*   Updated: 2017/12/01 16:04:00 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;
	unsigned int	size;

	if (s == NULL || f == NULL)
		return (NULL);
	size = 0;
	while (s[size])
	{
		size++;
	}
	if ((size == 0) || ((new_str = malloc((size + 1) * sizeof(char))) == NULL))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

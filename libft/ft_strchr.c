/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:26:06 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/27 22:30:40 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	unsigned char	c_copy;
	int				i;

	c_copy = (unsigned char)c;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c_copy)
			return ((char*)s + i);
		i++;
	}
	if (c_copy == 0)
		return ((char*)s + i);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:49:26 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/27 22:31:33 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	unsigned char	c_copy;
	int				i;

	c_copy = (unsigned char)c;
	i = 0;
	while (s[i] != 0)
		i++;
	while (i >= 0)
	{
		if (s[i] == c_copy)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

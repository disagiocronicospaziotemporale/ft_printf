/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:05:23 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/30 21:31:54 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_copy;
	size_t			i;

	s_copy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_copy[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

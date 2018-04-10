/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:40:37 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/27 19:30:00 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dst_copy;
	const unsigned char	*src_copy;
	unsigned char		c_copy;
	void				*pointer;

	dst_copy = (unsigned char *)dst;
	src_copy = (const unsigned char *)src;
	c_copy = (unsigned char)c;
	pointer = NULL;
	i = 0;
	while (i < n)
	{
		dst_copy[i] = src_copy[i];
		i++;
		if (src_copy[i - 1] == c_copy)
		{
			pointer = dst + i;
			break ;
		}
	}
	return (pointer);
}

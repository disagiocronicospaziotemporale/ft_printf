/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:43:59 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/27 19:37:08 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_copy;
	const unsigned char	*src_copy;

	dst_copy = (unsigned char *)dst;
	src_copy = (const unsigned char *)src;
	i = 0;
	if (dst_copy < src_copy)
		while (i < n)
		{
			dst_copy[i] = src_copy[i];
			i++;
		}
	else if (dst_copy > src_copy)
		while (n > 0)
		{
			dst_copy[n - 1] = src_copy[n - 1];
			n--;
		}
	return (dst);
}

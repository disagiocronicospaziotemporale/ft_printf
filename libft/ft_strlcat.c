/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:23:12 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/30 20:54:14 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	ldst;
	unsigned int	lsrc;
	unsigned int	i;

	ldst = 0;
	while (dst[ldst])
		ldst++;
	lsrc = 0;
	while (src[lsrc])
		lsrc++;
	if (size == 0)
		return (lsrc);
	i = 0;
	while (ldst + i < size - 1 && src[i])
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = 0;
	if (ldst < size)
		return (lsrc + ldst);
	else
		return (lsrc + size);
}

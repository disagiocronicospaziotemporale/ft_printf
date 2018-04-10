/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:44:05 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/17 15:24:58 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_copy;

	c = (unsigned char)c;
	b_copy = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		b_copy[i] = c;
		i++;
	}
	return (b);
}

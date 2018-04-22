/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:36:11 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/21 20:39:28 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//flags che devono fungere '0"zeros instead of spaces"' '-"left jusify"' 'min-wight'

#include "ft_printf.h"

unsigned int perc(unsigned int *flags, va_list *list)
{
	unsigned int n;
	unsigned int i;
	char fill_char;

	(void)list;
	n = flags[5] + 1;

	if(flags[1])
		fill_char = '0';
	else
		fill_char = ' ';

	if(flags[2])
	{
		write(1, "%", 1);
		i = 0;
		while(i++ < n - 1)
			write(1, &fill_char, 1);
	}
	else
	{
		i = 0;
		while(i++ < n - 1)
			write(1, &fill_char, 1);
		write(1, "%", 1);
	}
	return (n);
}

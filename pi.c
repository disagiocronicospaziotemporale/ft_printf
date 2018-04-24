/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/24 19:43:11 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int pi(unsigned int *flags, va_list *list)
{
	unsigned int max_spaces;
	unsigned int precision;
	unsigned int i;
	char fill_char;
	intmax_t x;


	//12 ll
	//11 hh
	//10 l
	//9 h
	//8 z
	//7 j
	
	x = size_manager_d('i', flags, list);

	max_spaces = flags[5] + 1;
	precision = flags[6];
	

	if(flags[1])
		fill_char = '0';
	else
		fill_char = ' ';

	if(flags[2])
	{
		write(1, &c, 1);
		i = 0;
		while(i++ < n - 1)
			write(1, &fill_char, 1);
	}
	else
	{
		i = 0;
		while(i++ < n - 1)
			write(1, &fill_char, 1);
		write(1, &c, 1);
	}
	return (n);
}

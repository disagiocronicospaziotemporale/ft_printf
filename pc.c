/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/21 21:31:58 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int pc(unsigned int *flags, va_list *list)
{
	unsigned int n;
	unsigned int i;
	char fill_char;
	char c;

	    c = va_arg(*list, char);
	n = flags[5] + 1;

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

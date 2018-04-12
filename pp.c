/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/12 23:44:59 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int pp(unsigned int *flags, va_list *list)
{
	unsigned int n;
	void *p;
	char fill_char;

	n = flags[5] + 1;

	p = va_arg(*list, void*);

	if(flags[1])
		fill_char = '0';
	else
		fill_char = ' ';

	if(flags[2])
	{
		write(1, '%', 1);
		i = 0;
		while(i++ < n - 1)
			write(1, &fill_char, 1);
	}
	else
	{
		i = 0;
		while(i++ < n - 1)
			write(1, &fill_char, 1);
		write(1, '%', 1);
	}
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/05/21 17:13:01 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int pcc(unsigned int *flags, va_list *list)
{
	unsigned int n;
	unsigned int i;
	char *wstr;

	wstr = convertunicode((wchar_t)va_arg(*list, wchar_t));
	n = flags[5];

	if(flags[2])
	{
		write(1, wstr, 1);
		i = 0;
		while(i++ < n)
			write(1, " ", 1);
	}
	else
	{
		i = 0;
		while(i++ < n)
				write(1, " ", 1);
		write(1, wstr, 1);
	}
	return (n + 1);
}

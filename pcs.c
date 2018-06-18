/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/06/18 19:37:53 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int pcs(unsigned int *flags, va_list *list)
{
	char *wstr;
	unsigned int n;
	unsigned int l;
	unsigned int sum;

	wstr = strunicode((wchar_t *)va_arg(*list, wchar_t*));
	//nofinitoooooo
	l = unicodestrlen(wstr);
	if (fags[6] < l)
		l = flags[6];

	n = flags[5];
if(n > l)
{
	sum = 0;
	if(flags[2])
	{
		sum = sum + write(1, wstr, l);
		i = 0;
		while(i++ < n - l)
			sum = sum + write(1, " ", 1);
	}
	else
	{
		i = 0;
		while(i++ < n - l)
			sum = sum + write(1, " ", 1);
		sum = sum + write(1, wstr, l);
	}

	return (sum);
}
else
{
sum = write(1, wstr, n);
return (sum);
}
}

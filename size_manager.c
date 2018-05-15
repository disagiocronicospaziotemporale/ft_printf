/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:43:06 by mriccard          #+#    #+#             */
/*   Updated: 2018/05/09 19:39:06 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	size_flags_short(unsigned int *flags, unsigned int *monoflag)
{
	*monoflag = 1;
	if (flags[8])
		*monoflag = 7;
	else if (flags[12])
		*monoflag = 6;
	else if (flags[10])
		*monoflag = 5;
	else if (flags[7])
		*monoflag = 4;
	else if (flags[11])
		*monoflag = 2;
	else if(flags[9])
		*monoflag = 3;
}

intmax_t	size_manager_d(char type, unsigned int *flags, va_list *list)
{
	unsigned int monoflag;

	size_flags_short(flags, &monoflag);

	if (monoflag == 2 && type != 'D')
		return ((long long)((signed char)va_arg(*list, int)));
	else if (monoflag == 1 && type != 'D')
		return ((int)(va_arg(*list, int)));
	else if (monoflag == 3 && type != 'D')
		return ((long long)((short int)va_arg(*list, int)));
	else if (monoflag == 6)
		return ((long long)va_arg(*list, long long));
	else if (monoflag == 4)
		return ((intmax_t)va_arg(*list, intmax_t));
	else if (monoflag == 7)
		return ((long long)va_arg(*list, size_t));
	else
		return ((long long)va_arg(*list, long));
}
uintmax_t	size_manager_u(char type, unsigned int *flags, va_list *list)
{
	unsigned int monoflag;

	size_flags_short(flags, &monoflag);

	if (monoflag == 1 && type != 'U' && type != 'O')
		return ((unsigned int)(va_arg(*list, unsigned long long)));
	else if (monoflag == 2 && type != 'U' && type != 'O')
		return ((long long)((unsigned char)va_arg(*list, int)));
	else if (monoflag == 3 && type != 'U' && type != 'O')
		return (((unsigned long long)(unsigned short int)va_arg(*list, int)));
	else if (monoflag == 6)
		return ((unsigned long long)va_arg(*list, unsigned long long));
	else if (monoflag == 7)
		return ((unsigned long long)va_arg(*list, size_t));
	else if (monoflag == 4)
		return ((uintmax_t)va_arg(*list, uintmax_t));
	else
		return ((unsigned long)va_arg(*list, uintmax_t));
}

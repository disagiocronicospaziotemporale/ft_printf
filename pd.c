/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/03/30 19:46:42 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int pd(va_list *list)
{


	char *str;
	int x;
	unsigned int n;

	x = va_arg(*list, int);
	str = ft_itoa(x);
	n = ft_strlen(str);
	write(1, str, n);
	free(str);
	return (n);
}

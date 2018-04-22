/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/21 20:29:35 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int ps(unsigned int *flags, va_list *list)
{
	char *str;
	unsigned int n;

	str = va_arg(*list, char*);
	n = ft_strlen(str);
	write(1, str, n);
	return (n);
}

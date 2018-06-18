/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/05/16 16:29:12 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int ps(unsigned int *flags, va_list *list)
{
	char *str;
	unsigned int n;

	str = va_arg(*list, char*);
	str = ft_strdup(str);
	str = precision_manager('s', flags, str);
	str = min_spaces_manager(flags, str);
	n = ft_strlen(str);
	n = write(1, str, n);
	if(str)
		free(str);
	return (n);
}

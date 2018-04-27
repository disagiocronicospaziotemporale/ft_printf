/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:25:15 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/27 19:56:25 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void size_and_precision_manager(unsigned int *flags, char *str)
{
	unsigned int l;
	unsigned int minus;

	l = ft_strlen(str);
	if (str[0] == '-')
		minus = 1;
	else
		minus = 0;
	if((l - minus) > flags[6])
}

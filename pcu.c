/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:28:51 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/21 20:36:04 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int pcu(unsigned int *flags, va_list *list)
{
write(1, "\npcu\n", 5);
return (3);
}

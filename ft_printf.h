/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:52:31 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/11 14:15:09 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int			ft_printf (char *str, ...);

char		*ft_itoa_base(intmax_t v, int base);

unsigned int ps(va_list *list);

unsigned int pcs(va_list *list);

unsigned int pp(va_list *list);

unsigned int pd(va_list *list);

unsigned int pcd(va_list *list);

unsigned int pi(va_list *list);

unsigned int po(va_list *list);

unsigned int pco(va_list *list);

unsigned int pu(va_list *list);

unsigned int pcu(va_list *list);

unsigned int px(va_list *list);

unsigned int pcx(va_list *list);

unsigned int pc(va_list *list);

unsigned int pcc(va_list *list);

unsigned int bt(va_list *list);

#endif

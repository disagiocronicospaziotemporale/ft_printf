/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:52:31 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/28 16:26:21 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>

int			ft_printf (char *str, ...);

char		*ft_itoa_base(intmax_t v, int base);

unsigned int ps(unsigned int *flags, va_list *list);

unsigned int pcs(unsigned int *flags, va_list *list);

unsigned int pp(unsigned int *flags, va_list *list);

unsigned int pd(unsigned int *flags, va_list *list);

unsigned int pcd(unsigned int *flags, va_list *list);

unsigned int pi(unsigned int *flags, va_list *list);

unsigned int po(unsigned int *flags, va_list *list);

unsigned int pco(unsigned int *flags, va_list *list);

unsigned int pu(unsigned int *flags, va_list *list);

unsigned int pcu(unsigned int *flags, va_list *list);

unsigned int px(unsigned int *flags, va_list *list);

unsigned int pcx(unsigned int *flags, va_list *list);

unsigned int pc(unsigned int *flags, va_list *list);

unsigned int pcc(unsigned int *flags, va_list *list);

unsigned int perc(unsigned int *flags, va_list *list);

unsigned int pj(unsigned int *flags, va_list *list);

unsigned int pz(unsigned int *flags, va_list *list);

unsigned int pl(unsigned int *flags, va_list *list);

unsigned int ph(unsigned int *flags, va_list *list);

unsigned int pll(unsigned int *flags, va_list *list);

unsigned int phh(unsigned int *flags, va_list *list);

unsigned int bt(unsigned int *flags, va_list *list);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:50:46 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/28 17:04:16 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static char	*charadder(char *str, int nb)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	while (str[i])
		i++;
	str = (char*)malloc(sizeof(char) * (i + 2));
	i = 0;
	str[i] = (nb > 9) ? nb + 55 : nb + 48;
	while (tmp[i])
	{
		str[i + 1] = tmp[i];
		i++;
	}
	str[i + 1] = 0;
	free(tmp);
	return (str);
}

char		*ft_utoa_base(uintmax_t v, int base)
{
	char		*str;

	if (base < 2 || base > 16)
		return (NULL);
	str = (char*)malloc(sizeof(char));
	str[0] = 0;
	while (v / base > 0)
	{
		str = charadder(str, v % base);
		v = v / base;
	}
	str = ft_charadder(str, v);
	return (str);
}

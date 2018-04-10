/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:10:46 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/30 20:52:14 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digit(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		write_digit(int n, char *s, int len)
{
	s[len] = 0;
	len--;
	while (len >= 0)
	{
		s[len] = (n % 10) + '0';
		len--;
		n = n / 10;
	}
}

char			*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	len = count_digit(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		neg = neg + 1;
	}
	write_digit(n, s, len);
	if (neg > 0)
		s[0] = '-';
	return (s);
}

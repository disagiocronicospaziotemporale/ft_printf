/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 03:49:27 by mriccard          #+#    #+#             */
/*   Updated: 2017/11/30 20:59:14 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		menus(const char **str_pt, int *meno_pt)
{
	if (*str_pt[0] == '-')
	{
		*meno_pt = -1;
		*str_pt = *str_pt + 1;
	}
	else if (*str_pt[0] == '+')
		*str_pt = *str_pt + 1;
}

int				ft_atoi(const char *str)
{
	int			meno;
	int			res;
	int			z;
	int			i;

	meno = 1;
	i = 0;
	z = 1;
	res = 0;
	while (*str && (*str == '\n' || *str == '\t' || *str == ' '
			|| *str == '\f' || *str == '\r' || *str == '\v'))
		str++;
	menus(&str, &meno);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	while (i >= 0)
	{
		res = res + z * (str[i] - 48);
		z = z * 10;
		i--;
	}
	return (res * meno);
}

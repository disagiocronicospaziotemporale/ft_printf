/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:41:47 by mriccard          #+#    #+#             */
/*   Updated: 2017/12/01 14:43:55 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int tot;

	if (power > 1)
	{
		tot = 1;
		tot = nb * ft_power(nb, power - 1);
		return (tot);
	}
	else if (power == 1)
		return (nb);
	else if (power == 0)
		return (1);
	else
		return (0);
}

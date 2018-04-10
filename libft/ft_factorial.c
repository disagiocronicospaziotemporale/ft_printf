/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:46:14 by mriccard          #+#    #+#             */
/*   Updated: 2017/12/01 14:46:43 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_factorial(int nb)
{
	int	tot;

	if (nb > 0 && nb < 13)
	{
		tot = nb;
		tot = tot * ft_factorial(nb - 1);
		return (tot);
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

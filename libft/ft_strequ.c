/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:01:42 by mriccard          #+#    #+#             */
/*   Updated: 2017/12/01 20:04:36 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	else
	{
		i = 0;
		while (s1[i] == s2[i] && s1[i] && s2[i])
			i++;
		if (s1[i] == 0 && s2[i] == 0)
			return (1);
		else
			return (0);
	}
}

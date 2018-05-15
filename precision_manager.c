/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:02:35 by mriccard          #+#    #+#             */
/*   Updated: 2018/05/15 18:10:40 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *precision_manager(char type, unsigned int *flags, char *str)
{
	char *new_str;
	unsigned int l;
	unsigned int i;

	l = ft_strlen(str);
	if(flags[6] < 0)
		return(str);
	if ((type == 's' || type == 'S') && l > flags[6])
	{
		new_str = ft_strnew(flags[6]);
		ft_strncpy(new_str, str, flags[6]);
	}
	else if (type != 'c' && type != 'C' && type != 's' && type != 'S' && l < flags[6])
	{
		new_str = ft_strnew(flags[6]);
		ft_strcpy(new_str + (flags[6] - l), str);
		i = 0;
		while(i < (flags[6] - l))
		{
			new_str[i] = '0';
			i++;
		}
	}
	else
		return(str);

	free(str);
	return (new_str);
}

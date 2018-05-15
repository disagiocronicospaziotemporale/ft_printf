/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:25:15 by mriccard          #+#    #+#             */
/*   Updated: 2018/05/15 17:50:32 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const unsigned int str_all_diff(char *str, char x)
{
	while(*str)
	{
		if(*str != x)
			return (1);
		str = str + 1;
	}
	return (0);
}

char *plus_and_space_manager(char type, unsigned int *flags, char *str);
{
	char *new_str;
	unsigned int l;

	//if (flags[3] == 0 && flags[4] == 0)
		//return (str);
	if (type != 'd' && type != 'i')
		return (str);
	if(str[0] == '-')
		return (str);
	if(flags[3] != 0)
	{
		l = ft_strlen(str);
		new_str = ft_strnew(l + 1);
		ft_strcpy(new_str + 1, str);
		new_str[0] = '+';
	}
	else if(flags[4] != 0)
	{
		l = ft_strlen(str);
		new_str = ft_strnew(l + 1);
		ft_strcpy(new_str + 1, str);
		new_str[0] = ' ';
	}
	else
		return (str);
		
		free(str);
		return (new_str);
}

char *prefix_manager(char type, unsigned int *flags, char *str)
{
	char *new_str;
	unsigned int l;

	if(flags[0] == 0)
		return (str);
	if (type == 'o')
	{
		l = ft_strlen(str);
		new_str = ft_strnew(l + 1);
		ft_strcpy(new_str + 1, str);
		new_str[0] = '0';
	}
	else if ((type == 'x' || type == 'X') && str_all_diff(*str, '0') == 1)
	{
		l = ft_strlen(str);
		new_str = ft_strnew(l + 2);
		ft_strcpy(new_str + 2, str);
		new_str[0] = '0';
		new_str[1] = type;
	}
	else
		return (str);
	free(str);
	return (new_str);

}

char *min_spaces_manager(unsigned int *flags, char *str)
{
	unsigned int l;
	unsigned int i;
	char *new_str;
	char fill_char;

	l = ft_strlen(str);
	if(l >= flags[5])
		return(str);
	new_str = ft_strnew(flags[5]);
	if(flags[1] && flags[2] == 0 && flags[6] != -1)
		fill_char = '0';
	else
		fill_char = ' ';
	if(flags[2])
		ft_strcpy(new_str, str);
	else
		ft_strcpy(new_str + (flags[5] - l), str);
	i = 0;
	while (i < flags[5] - l)
	{
		new_str[i + (l * flags[2])] = fill_char;
		i++;
	}
	free(str);
	return (new_str);
}

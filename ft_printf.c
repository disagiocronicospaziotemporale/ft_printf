/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:31:30 by mriccard          #+#    #+#             */
/*   Updated: 2018/05/15 17:26:22 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int magic(char **str, va_list *list, unsigned int *flags)
{
	const char l[15] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','C','%'};
	unsigned int(*func[16])(unsigned int *flags, va_list *list) = {ps, pcs, pp, pi, pcd, pi, po, pco, pu, pcu, px, pcx, pc, pcc, perc, bt};
	unsigned int i;

	i = 0;
	while ((*str)[i] == 'j' || (*str)[i] == 'z' || (*str)[i] == 'h' || (*str)[i] == 'l')
	{
		flags[7] = (((*str)[i])) == 'j';
		flags[8] = (((*str)[i])) == 'z';
		if (((*str)[i]) == 'h')
		{
			if(((*str)[i + 1]) == 'h')
			{
				flags[11] = 1;
				i++;
			}
			else
				flags[9] = 1;
		}
		if (((*str)[i]) == 'l')
		{
			if(((*str)[i + 1]) == 'l')
			{
				flags[12] = 1;
				i++;
			}
			else
				flags[10] = 1;
		}
		i++;
	}
	*str = (*str) + i;
	i = 0;
	while (i < 19 && l[i] != (*str)[0])
		i++;
	*str = (*str) + 1;
	return((*func[i])(flags, list));
}

static unsigned int flags_manager(char **str, va_list *list, unsigned int *flags)
{
	int i;
	unsigned int dotflag;

		i = 1;
	while ((*str)[i] == '#' || (*str)[i] == '0' || (*str)[i] == '-' || (*str)[i] == '+' || (*str)[i] == ' ')
	{
		flags[0] = (((*str)[i]) == '#');
		flags[1] = (((*str)[i]) == '0');
		flags[2] = (((*str)[i]) == '-');
		flags[3] = (((*str)[i]) == '+');
		flags[4] = (((*str)[i]) == ' ');
		i++;
	}

	while((*str)[i] == '*' || (*str)[i] == '.' || ft_isdigit((*str)[i]))
	{
		if((*str)[i - 1] == '.')
		{
			dotflag = 1;
		}
		else
		{
			dotflag = 0;
		}

		if((*str)[i] == '*')
		{
			flags[5 + dotflag] = (unsigned int) ft_atoi(va_arg(*list, char*));
			i++;
		}
		else if((*str)[i] == '.')
		{
			i++;
		}
		else
		{
			flags[5 + dotflag] = (unsigned int) ft_atoi((*str) + i);
			while(ft_isdigit((*str)[i]))
				i++;
		}
	}
	if((*str)[i - 1] == '.')
		flags[6] = 0;
		return (i);
}

static unsigned int ppjn(char **str, va_list *list)
{
	unsigned int i;
	unsigned int count;
	unsigned int flags[13];

	if (*str == NULL)
		return (0);
	i = 0;
	while (i < 13)
		flags[i++] = 0;
	flags[6] = -1;
	i = 0;
	i = flags_manager(str, list, flags);
	*str = (*str) + i;
	count = magic(str, list, flags);
	return (count);
}

static unsigned int pupjn(char **str)
{
	unsigned int count;
	char *nxt_percent;

	if ((nxt_percent = ft_strchr(*str, '%')) != NULL)
		count = nxt_percent - *str;
	else
		count = ft_strlen(*str);

	if (count > 0)
		write(1,*str,count);
	*str = nxt_percent;
	return (count);
}

int	ft_printf (char *str, ... )
{
	va_list list;
	char *nxt;
	unsigned int count;

	count = 0;
	nxt = str;
	va_start(list, str);	
	while (nxt && *nxt)
	{
		count = count + pupjn(&nxt);
		count = count + ppjn(&nxt, &list);
	}
	va_end(list);
	return (count);
}

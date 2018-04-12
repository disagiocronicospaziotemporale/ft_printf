/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:31:30 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/12 22:03:53 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int magic(char **str, va_list *list, unsigned int *flags)
{
	const char l[19] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','C','%','j','z','l','h'};
	unsigned int(*func[22])(unsigned int *flags, va_list *list) = {ps, pcs, pp, pd, pcd, pi, po, pco, pu, pcu, px, pcx, pc, pcc, perc, pj, pz, pl, ph, bt, pll, phh};
	unsigned int i;

	i = 0;
	while (i < 19 && l[i] != (*str)[0])
		i++;
	if ((i == 17 || i == 18) && (*str)[1] == l[i])
	{
		i = i + 3;
		(*str) = (*str) + 1;
	}
		(*str) = (*str) + 1;
	return((*func[i])(flags, list));

}

static unsigned int flags_manager(char **str, va_list *list, unsigned int *flags)
{
	int i;
	int j;
	unsigned int dotflag

	i = 1;
	while ((*str)[i] == '#' || (*str)[i] == '0' || (*str)[i] == '-' || (*str)[i] == '+' || (*str)[i] == ' ')
	{
		flags[0] = ((*str)[i]) == '#';
		flags[1] = ((*str)[i]) == '0';
		flags[2] = ((*str)[i]) == '-';
		flags[3] = ((*str)[i]) == '+';
		flags[4] = ((*str)[i]) == ' ';
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
		while(ft_sidigit((*str)[i]))
			            i++;
	}
}
	return (i);
}

static unsigned int ppjn(char **str, va_list *list)
{
	unsigned int i;
	unsigned int count;
	unsigned int flags[7];

	if (*str == NULL)
		return (0);
	i = flags_manager(str, flags);
	count = magic((*str) + i, list, flags);
	//ORA LO FA DENTRO MAGI COL PUNTATORE *str = (*str) + i + 1; //da per scontato che la lettera dopo il percentio sia una e solo una, MALE!!!!
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:31:30 by mriccard          #+#    #+#             */
/*   Updated: 2018/04/10 20:58:26 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int magic(char t, va_list *list, int *flags)
{
	const char l[26] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','C','e','E','f','F','g','G','a','A','n','b','r','k'};
	unsigned int(*func[27])(va_list *list) = {ps, pcs, pp, pd, pcd, pi, po, pco, pu, pcu, px, pcx, pc, pcc,,,,,,,,,,,,, bt};
	unsigned int i;

	i = 0;
	while (i < 26 && l[i] != t)
		i++;
	return((*func[i])(list));

}

static flags_manager(str, unsigned int *min-spaces, va_list *list, int *flags)
{
	int i;
	int j;
	int flags[5] = {0,0,0,0,0}

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
	if((*str)[i] == '*')
	{
		if((ft_isdigit(*str)[i + 1]))
		{
			i++;
			*min-spaces = (unsigned int) ft_atoi((*str) + i);
			while (ft_isdigit((*str)[i]))
				i++;
		}
		else
		{
			*min-spaces = (unsigned int) ft_atoi(va_arg(*list, char*));
			i++;
		}
		//se quello dopo e un numero allora prendi il numero se no prendi va_arg e viceversa se prima c'e il numero e poi asterisco prendi va arg se no il numero
	}
	else if(ft_sidigit((*str)[i]))
	{
		j = 0;
		while(ft_sidigit((*str)[i + j]))
			j++;
		if((*str)[i + j] == '*')
		{
			i = i + j;
			*min-spaces = (unsigned int) ft_atoi(va_arg(*list, char*));
			i++;
		}
		else
		{
			*min-spaces = (unsigned int) ft_atoi((*str) + i);
				i = i + j;
		}
	}
	return (i);
}

static unsigned int ppjn(char **str, va_list *list)
{
	unsigned int i;
	unsigned int count;
	unsigned int min-spaces;

	if (*str == NULL)
		return (0);
	if((*str)[1] == '%')
	{
		write(1,"%",1);
		*str = *str + 2;
		return (1);
	}
	i = flags_manager(str, &min-spaces, flags);
	count = magic((*str)[i], list, flags);
	*str = (*str) + i + 1; //da per scontato che la lettera dopo il percentio sia una e solo una, MALE!!!!
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

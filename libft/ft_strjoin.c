/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:42:27 by mriccard          #+#    #+#             */
/*   Updated: 2017/12/01 16:07:55 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	len;
	unsigned int	i;

	if (s1 == NULL | s2 == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	i = 0;
	while (s2[i])
		i++;
	len = len + i;
	if ((new_str = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = 0;
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:09:01 by mriccard          #+#    #+#             */
/*   Updated: 2017/12/01 18:06:46 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*new_str;

	if (s == NULL)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	len = 0;
	while (s[len])
		len++;
	while (len > 0 && (s[len - 1] == ' ' ||
				s[len - 1] == '\t' || s[len - 1] == '\n'))
		len--;
	if ((new_str = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

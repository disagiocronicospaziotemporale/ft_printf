/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:52:39 by mriccard          #+#    #+#             */
/*   Updated: 2018/05/21 16:55:20 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*convertunicode(wchar_t c)
{
	char	*str;

	str = ft_strnew(4);
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) + 0xC0;
		str[1] = (c & 0x3F) + 0x80;
	}
	else if (c < 0xFFFF)
	{
		str[0] = (c >> 12) + 0xE0;
		str[1] = ((c >> 6) & 0x3F) + 0x80;
		str[2] = (c & 0x3F) + 0x80;
	}
	else
	{
		str[0] = ((c >> 18) + 0xF0);
		str[1] = ((c >> 12) & 0x3F) + 0x80;
		str[2] = ((c >> 6) & 0x3F) + 0x80;
		str[3] = (c & 0x3F) + 0x80;
	}
	return (str);
}

char	*strunicode(wchar_t *s)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*del;

	if (!s || !(str = ft_strnew(0)))
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		del = str;
		tmp = ft_convertunicode(s[i]);
		str = ft_strjoin(str, tmp);
		free(del);
		free(tmp);
		i++;
	}
	return (str);
}

unsigned int unicodestrlen(wchar_t *s)
{
	unsigned int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);

}

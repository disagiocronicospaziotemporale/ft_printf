#include "libft.h"

static char	*charadder(char *str, int nb)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	while (str[i])
		i++;
	str = (char*)malloc(sizeof(char*) * (i + 2));
	str[i] = (nb > 9) ? nb + 55 : nb + 48;
	i = 0;
	while (tmp[i])
	{
		str[i + 1] = tmp[i];
		i++;
	}
	str[i + 1] = 0;
	free(tmp);
	return (str);
}

char		*ft_itoa_base(intmax_t v, int base)
{
	int		minus;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	minus = (v < 0);
	v = (v < 0) ? -v : v;
	str = (char*)malloc(sizeof(*str));
	str[0] = 0;
	while (v / base > 0)
	{
		str = charadder(str, v % base);
		v = v / base;
	}
	str = charadder(str, v);
	str = (minus == 1 && base == 10) ? charadder(str, -3) : str;
	return (str);
}

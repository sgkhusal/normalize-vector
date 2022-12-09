/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:20:40 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/08 18:21:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normalize.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	return_not_int(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

static int	ft_atoi(const char *nptr)
{
	unsigned long long	n;
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (n > 9223372036854775807)
		return (return_not_int(sign));
	return (n * sign);
}

double	ft_atod(char *nb)
{
	double	n;
	int		point;
	int		size;

	size = ft_strlen(nb);
	point = 0;
	while (nb[point] != '.' && point < size)
		point++;
	if (point == size)
		return (ft_atoi(nb));
	ft_memmove(nb + point, nb + point + 1, size - point);
	n = ft_atoi(nb);
	n /= pow(10, size - point - 1);
	return (n);
}

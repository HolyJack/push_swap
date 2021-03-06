/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:43:42 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 02:54:00 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *s)
{
	long	buf;
	int		sign;
	char	*str;

	sign = 1;
	str = (char *) s;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	buf = 0;
	while (ft_isdigit(*str) == 1)
	{
		buf *= 10;
		buf += (*str - '0');
		str++;
		if ((sign == 1 && buf > 2147483647) || buf > 2147483648)
			return (0);
	}
	return (sign * buf);
}

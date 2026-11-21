/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 14:19:16 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 13:23:24 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overflow(long result, int sign)
{
	if (sign == 1 && result > INT_MAX)
		return (-1);
	if (sign == -1 && result > (long)INT_MAX + 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *s, int *out)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (!s || !*s)
		return (-1);
	if (ft_issign(*s))
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		return (-1);
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	if (*s != '\0')
		return (-1);
	if (overflow(result, sign) < 0)
		return (-1);
	*out = (int)(result * sign);
	return (0);
}

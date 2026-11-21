/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:58:48 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/20 16:01:11 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

double	compute_disorder(t_ps *ps)
{
	double	mistakes;
	double	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	if (ps->a.size < 2)
		return (0.0);
	while (i < ps->a.size)
	{
		j = i + 1;
		while (j < ps->a.size)
		{
			total_pairs += 1;
			if (stack_get(&ps->a, i) > stack_get(&ps->a, j))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:56:54 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 10:27:32 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *s)
{
	int	i;
	int	min_idx;

	i = 1;
	min_idx = 0;
	while (i < (int)s->size)
	{
		if (stack_get(s, i) < stack_get(s, min_idx))
			min_idx = i;
		i++;
	}
	return (min_idx);
}

static void	bring_min_to_top(t_ps *ps)
{
	size_t	size;
	int		min_idx;
	int		i;

	size = ps->a.size;
	min_idx = find_min_index(&ps->a);
	if (min_idx <= (int)(size / 2))
	{
		i = 0;
		while (i < min_idx)
		{
			op(ps, OP_RA);
			i++;
		}
	}
	else
	{
		i = size - min_idx;
		while (i > 0)
		{
			op(ps, OP_RRA);
			i--;
		}
	}
}

void	sort_simple(t_ps *ps)
{
	while (ps->a.size > 3)
	{
		bring_min_to_top(ps);
		op(ps, OP_PB);
	}
	sort_small(ps);
	while (ps->b.size > 0)
		op(ps, OP_PA);
}

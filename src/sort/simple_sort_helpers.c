/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 10:27:46 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 12:24:17 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_2(t_ps *ps)
{
	int	a;
	int	b;

	a = stack_get(&ps->a, 0);
	b = stack_get(&ps->a, 1);
	if (b < a)
		op(ps, OP_RA);
}

void	sort_3(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = stack_get(&ps->a, 0);
	b = stack_get(&ps->a, 1);
	c = stack_get(&ps->a, 2);
	if (a > b && b < c && a < c)
		op(ps, OP_SA);
	else if (a > b && b > c && a > c)
	{
		op(ps, OP_SA);
		op(ps, OP_RRA);
	}
	else if (a > b && b < c && a > c)
		op(ps, OP_RA);
	else if (a < b && b > c && a < c)
	{
		op(ps, OP_SA);
		op(ps, OP_RA);
	}
	else if (a < b && b > c && a > c)
		op(ps, OP_RRA);
}

void	sort_small(t_ps *ps)
{
	if (ps->a.size == 2)
		sort_2(ps);
	if (ps->a.size == 3)
		sort_3(ps);
}

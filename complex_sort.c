/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:44:36 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 11:24:36 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bit(int n)
{
	int	max_rank;
	int	max_bit;

	max_bit = 0;
	max_rank = n - 1;
	while (max_rank > 0)
	{
		max_rank /= 2;
		max_bit++;
	}
	return (max_bit);
}

static void	sort_bit(t_ps *ps, size_t n, int bit)
{
	size_t	i;
	int		x;

	i = 0;
	while (i < n)
	{
		x = stack_get(&ps->a, 0);
		if ((x >> bit) & 1)
			op(ps, OP_RA);
		else
			op(ps, OP_PB);
		i++;
	}
}

static void	restore_stack_a(t_ps *ps)
{
	while (ps->b.size > 0)
		op(ps, OP_PA);
}

int	sort_complex(t_ps *ps)
{
	size_t	n;
	int		bit;
	int		max_bit;

	n = ps->a.size;
	bit = 0;
	max_bit = get_max_bit(n);
	if (assign_ranks(&ps->a) < 0)
		return (-1);
	while (bit < max_bit)
	{
		sort_bit(ps, n, bit);
		restore_stack_a(ps);
		bit++;
	}
	return (0);
}

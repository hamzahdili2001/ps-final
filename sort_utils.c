/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:45:14 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 12:04:18 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rank(t_stack *s, int *ranks)
{
	int	i;

	if (!ranks)
		return ;
	i = 0;
	while (i < (int)s->size)
	{
		s->data[(s->head + i) % s->cap] = ranks[i];
		i++;
	}
}

int	assign_ranks(t_stack *a)
{
	int	*ranks;
	int	i;
	int	j;
	int	count;

	ranks = malloc(sizeof(int) * a->size);
	if (!ranks)
		return (-1);
	i = 0;
	while (i < (int)a->size)
	{
		count = 0;
		j = 0;
		while (j < (int)a->size)
		{
			if (j != i && stack_get(a, j) < stack_get(a, i))
				count++;
			j++;
		}
		ranks[i] = count;
		i++;
	}
	rank(a, ranks);
	free(ranks);
	return (0);
}

int	is_sorted(t_ps *ps)
{
	int	i;

	i = 0;
	while (i + 1 < (int)ps->a.size)
	{
		if (stack_get(&ps->a, i) > stack_get(&ps->a, i + 1))
			return (-1);
		i++;
	}
	return (0);
}

int	sort_dispatch(t_ps *ps)
{
	ps->disorder = compute_disorder(ps);
	if (ps->adaptive == 1)
	{
		if (mode_adaptive(ps) < 0)
			return (-1);
	}
	else
	{
		if (ps->mode == MODE_SIMPLE)
			sort_simple(ps);
		if (ps->mode == MODE_MEDIUM)
		{
			if (sort_medium(ps) < 0)
				return (-1);
		}
		if (ps->mode == MODE_COMPLEX)
		{
			if (sort_complex(ps) < 0)
				return (-1);
		}
	}
	if (ps->bench == 1)
		print_bench(ps);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 10:10:04 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 11:56:32 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_allocate(t_stack *s, size_t cap)
{
	s->data = malloc(sizeof(int) * cap);
	if (!(s->data))
		return (-1);
	s->cap = cap;
	s->head = 0;
	s->size = 0;
	return (0);
}

void	ps_init(t_ps *ps)
{
	int	i;

	i = 0;
	ps->a.data = NULL;
	ps->a.head = 0;
	ps->a.cap = 0;
	ps->a.size = 0;
	ps->b.data = NULL;
	ps->b.head = 0;
	ps->b.cap = 0;
	ps->b.size = 0;
	ps->bench = 0;
	ps->silent = 0;
	ps->ops_count = 0;
	ps->mode = MODE_NONE;
	ps->disorder = 0.0;
	ps->adaptive = 0;
	while (i < OP_COUNT)
		ps->op_counts[i++] = 0;
}

void	free_ps(t_ps *ps)
{
	free(ps->a.data);
	free(ps->b.data);
	free(ps);
}

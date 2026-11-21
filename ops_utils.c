/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:05:30 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 13:08:22 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushes(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	stack_push(to, stack_pop(from));
}

void	stack_pushes(t_ps *ps, t_op code)
{
	if (code == OP_PA)
		pushes(&ps->b, &ps->a);
	if (code == OP_PB)
		pushes(&ps->a, &ps->b);
}

void	stack_swaps(t_ps *ps, t_op code)
{
	if (code == OP_SA || code == OP_SS)
		stack_swap(&ps->a);
	if (code == OP_SB || code == OP_SS)
		stack_swap(&ps->b);
}

void	stack_rotations(t_ps *ps, t_op code)
{
	if (code == OP_RA || code == OP_RR)
		stack_rotate(&ps->a);
	if (code == OP_RB || code == OP_RR)
		stack_rotate(&ps->b);
}

void	stack_rrotations(t_ps *ps, t_op code)
{
	if (code == OP_RRA || code == OP_RRR)
		stack_rrotate(&ps->a);
	if (code == OP_RRB || code == OP_RRR)
		stack_rrotate(&ps->b);
}

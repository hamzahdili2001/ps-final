/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:00:33 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 11:27:17 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*op_name(t_op code)
{
	static const char	*ops[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	if (code < 0 || code >= OP_COUNT)
		return ("");
	return (ops[code]);
}

static void	op_apply(t_ps *ps, t_op code)
{
	stack_swaps(ps, code);
	stack_pushes(ps, code);
	stack_rotations(ps, code);
	stack_rrotations(ps, code);
}

void	op(t_ps *ps, t_op code)
{
	op_apply(ps, code);
	ps->ops_count++;
	ps->op_counts[code]++;
	if (ps->silent)
		return ;
	ft_putendl_fd((char *)op_name(code), 1);
}

void	op_repeat(t_ps *ps, t_op code, int n)
{
	while (n-- > 0)
		op(ps, code);
}

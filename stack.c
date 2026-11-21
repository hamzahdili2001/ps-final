/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:27:40 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 13:19:19 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *s, int v)
{
	if (s->size >= s->cap)
		return ;
	s->head = (s->head - 1 + s->cap) % s->cap;
	s->data[s->head] = v;
	s->size++;
}

int	stack_pop(t_stack *s)
{
	int	v;

	if (s->size == 0)
		return (0);
	v = s->data[s->head % s->cap];
	s->head = (s->head + 1) % s->cap;
	s->size--;
	return (v);
}

void	stack_swap(t_stack *s)
{
	int	i0;
	int	i1;
	int	tmp;

	if (s->size < 2)
		return ;
	i0 = s->head;
	i1 = (s->head + 1) % s->cap;
	tmp = s->data[i1];
	s->data[i1] = s->data[i0];
	s->data[i0] = tmp;
}

void	stack_rotate(t_stack *s)
{
	int	v;

	if (s->size < 2)
		return ;
	v = stack_get(s, 0);
	s->head = (s->head + 1) % s->cap;
	s->data[(s->head + s->size - 1) % s->cap] = v;
}

void	stack_rrotate(t_stack *s)
{
	int	v;

	if (s->size < 2)
		return ;
	v = stack_get(s, s->size - 1);
	s->head = (s->head - 1 + s->cap) % s->cap;
	s->data[s->head] = v;
}

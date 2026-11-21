/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 13:37:30 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 09:30:45 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_ps *ps)
{
	double	precentage;
	long	decimal;
	long	fraction;

	precentage = ps->disorder * 100;
	decimal = (long)precentage;
	fraction = (long)((precentage - decimal) * 100);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(decimal, 2);
	ft_putchar_fd('.', 2);
	if (fraction < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(fraction, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_ps *ps)
{
	static const char *const	strategy_names[] = {"Simple", "Simple",
		"Medium", "Complex"};
	static const char *const	complexities[] = {"O(n²)", "O(n²)", "O(n√n)",
		"O(n log n)"};

	ft_putstr_fd("[bench] strategy: ", 2);
	if (ps->adaptive == 1)
	{
		ft_putstr_fd("Adaptive", 2);
		ft_putstr_fd(" / ", 2);
		ft_putstr_fd(complexities[ps->mode], 2);
	}
	else
	{
		ft_putstr_fd(strategy_names[ps->mode], 2);
		ft_putstr_fd(" / ", 2);
		ft_putstr_fd(complexities[ps->mode], 2);
	}
	ft_putstr_fd("\n", 2);
}

static void	print_counts(t_ps *ps, int from, int to)
{
	static const char	*op_name[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	ft_putstr_fd("[bench]", 2);
	while (from <= to)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(op_name[from], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(ps->op_counts[from], 2);
		from++;
	}
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_ps *ps)
{
	long	total;
	int		i;

	print_disorder(ps);
	print_strategy(ps);
	total = 0;
	i = 0;
	while (i < OP_COUNT)
		total += ps->op_counts[i++];
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_counts(ps, OP_SA, OP_PB);
	print_counts(ps, OP_RA, OP_RRR);
}

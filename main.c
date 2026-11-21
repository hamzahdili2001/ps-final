/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:40:43 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 10:25:06 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps	*init_push_swap(void)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (NULL);
	ps_init(ps);
	return (ps);
}

static int	run_push_swap(t_ps *ps)
{
	if (is_sorted(ps) == 0)
	{
		if (ps->bench == 1)
			print_bench(ps);
		return (0);
	}
	if (sort_dispatch(ps) < 0)
		return (0);
	return (0);
}

static int	cleanup_error(t_ps *ps, char **new_av)
{
	free_normalized_args(new_av);
	free_ps(ps);
	ft_putendl_fd("Error", 2);
	return (-1);
}

int	main(int ac, char **av)
{
	t_ps	*ps;
	char	**new_av;
	int		new_ac;

	if (ac <= 1)
		return (0);
	if (ac == 2 && ft_isflag(av[1]))
		return (0);
	ps = init_push_swap();
	if (!ps)
		return (-1);
	new_av = normalize_args(ac, av, &new_ac);
	if (!new_av)
		return (free_ps(ps), -1);
	if (parse_args(new_ac, new_av, ps) < 0)
		return (cleanup_error(ps, new_av));
	free_normalized_args(new_av);
	run_push_swap(ps);
	return (free_ps(ps), 0);
}

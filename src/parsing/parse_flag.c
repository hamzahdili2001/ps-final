/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:58:57 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 11:59:53 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isflag(char *s)
{
	return (s[0] == '-' && s[1] == '-');
}

static int	apply_flag(char *s, t_ps *ps)
{
	if (ft_strcmp(s, "--bench") == 0)
		return (ps->bench = 1, 0);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (ps->adaptive = 1, 0);
	if (ft_strcmp(s, "--simple") == 0)
		return (ps->mode = MODE_SIMPLE, ps->adaptive = 0, 0);
	else if (ft_strcmp(s, "--medium") == 0)
		return (ps->mode = MODE_MEDIUM, ps->adaptive = 0, 0);
	else if (ft_strcmp(s, "--complex") == 0)
		return (ps->mode = MODE_COMPLEX, ps->adaptive = 0, 0);
	else
		return (-1);
	return (0);
}

int	parse_flags(int ac, char **av, t_ps *ps)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_isflag(av[i]))
		{
			if (apply_flag(av[i], ps) < 0)
				return (-1);
		}
		i++;
	}
	if (ps->mode == MODE_NONE && ps->adaptive == 0)
		ps->adaptive = 1;
	return (i);
}

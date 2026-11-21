/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:38:50 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 10:21:45 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_token(char **str)
{
	char	*token;
	int		len;

	while (ft_isspace(**str))
		(*str)++;
	len = 0;
	while ((*str)[len] && !ft_isspace((*str)[len]))
		len++;
	token = ft_substr(*str, 0, len);
	if (!token)
		return (NULL);
	*str += len;
	return (token);
}

static int	count_args(int ac, char **av, int *new_ac)
{
	int	i;
	int	count;

	*new_ac = 1;
	i = 1;
	while (i < ac)
	{
		count = token_count(av[i++]);
		if (count == 0)
			return (-1);
		*new_ac += count;
	}
	return (0);
}

static int	fill_args(int ac, char **av, char **args)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < ac)
	{
		str = av[i++];
		while (token_count(str) > 0)
		{
			args[j] = get_token(&str);
			if (!args[j])
				return (free_partial(args, j), -1);
			j++;
		}
	}
	args[j] = NULL;
	return (0);
}

char	**normalize_args(int ac, char **av, int *new_ac)
{
	char	**args;

	if (count_args(ac, av, new_ac) < 0)
		return (NULL);
	args = malloc(sizeof(char *) * (*new_ac + 1));
	if (!args)
		return (NULL);
	args[0] = av[0];
	if (fill_args(ac, av, args) < 0)
		return (NULL);
	return (args);
}

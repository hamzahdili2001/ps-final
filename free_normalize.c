/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 10:21:11 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/21 10:21:57 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_partial(char **args, int count)
{
	while (count > 1)
		free(args[--count]);
	free(args);
}

void	free_normalized_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
		free(args[i++]);
	free(args);
}

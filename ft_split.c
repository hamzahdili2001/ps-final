/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 14:30:08 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 14:12:52 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	token_len(char *str)
{
	size_t	tlen;

	tlen = 0;
	while (*str && !ft_isspace(*str))
	{
		str++;
		tlen++;
	}
	return (tlen);
}

int	*ft_split(char *str, size_t *count_out)
{
	int		n;
	int		i;
	int		*arr;
	char	*token;

	n = token_count(str);
	if (!n)
		return (NULL);
	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (ft_isspace(*str++))
			continue ;
		str--;
		token = ft_substr(str, 0, token_len(str));
		if (!token || ft_atoi(token, &arr[i++]) < 0)
			return (free(token), free(arr), NULL);
		str += token_len(str);
		free(token);
	}
	*count_out = (size_t)i;
	return (arr);
}

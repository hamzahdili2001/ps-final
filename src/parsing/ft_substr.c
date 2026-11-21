/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 14:12:35 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/15 14:12:35 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static size_t	guard(size_t slen, unsigned int start, size_t len)
{
	size_t	count;

	if (start >= slen)
		count = 0;
	else if (len > slen - start)
		count = slen - start;
	else
		count = len;
	return (count);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	count;
	size_t	slen;
	size_t	i;
	char	*sub;

	slen = ft_strlen(str);
	count = guard(slen, start, len);
	sub = malloc(count + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < count)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

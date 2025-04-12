/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:17:15 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/12 22:17:16 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_word_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

static void	ft_free_ary(char **ary, int i)
{
	while (i >= 0)
	{
		free(ary[i]);
		i--;
	}
	free(ary);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		i;
	int		x;
	int		len;

	len = ft_word_count(s, c);
	rtn = malloc(sizeof(char *) * (len + 1));
	if (!rtn)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		while (*s == c)
			s++;
		x = 0;
		while (s[x] != c && s[x])
			x++;
		rtn[i] = ft_substr(s, 0, x);
		if (!rtn[i])
			return (ft_free_ary(rtn, i), NULL);
		s += x;
	}
	rtn[i] = NULL;
	return (rtn);
}

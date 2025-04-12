/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:16:55 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/12 22:16:56 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_s;

	total_s = count * size;
	ptr = malloc(total_s);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_s);
	return (ptr);
}

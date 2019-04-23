/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:18:09 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/11/05 10:56:00 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (src[0] == '\0')
		return ((char*)dest);
	while (dest[i] != '\0' && i < n)
	{
		j = 0;
		k = i;
		while (src[j] == dest[k] && dest[k] && k <= n)
		{
			if (src[j + 1] == '\0')
			{
				return ((char*)dest + i);
			}
			j++;
			k++;
		}
		i++;
	}
	return (0);
}

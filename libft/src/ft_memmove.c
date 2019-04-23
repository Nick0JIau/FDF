/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:12:59 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/11/06 17:37:34 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = -1;
	s = (char*)src;
	d = (char*)dest;
	if (s < d)
		while ((int)(--n) >= 0)
			*(d + n) = *(s + n);
	else
		while (++i < n)
			*(d + i) = *(s + i);
	return (dest);
}

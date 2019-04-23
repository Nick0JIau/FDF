/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:59:47 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/11/03 11:09:03 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	l;
	size_t	sl;

	l = 0;
	sl = ft_strlen((char*)src);
	while (*dest && n > 0)
	{
		dest++;
		l++;
		n--;
	}
	while (*src && n-- > 1)
		*dest++ = *src++;
	if (n == 0 || *src == 0)
		*dest = '\0';
	return (sl + l);
}

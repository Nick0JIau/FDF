/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:02:00 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/10/28 17:29:30 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	int				i;
	unsigned char	s;
	unsigned char	*str;

	i = 0;
	s = (unsigned char)c;
	str = (unsigned char*)arr;
	while (n--)
	{
		if (str[i] == s)
			return (str + i);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:06:36 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/10/27 13:21:44 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	s;
	int		i;

	i = 0;
	s = (char)c;
	while (*str)
	{
		str++;
		i++;
	}
	while (*str != s && i != 0)
	{
		str--;
		i--;
	}
	if (*str == s)
		return ((char*)str);
	return (0);
}

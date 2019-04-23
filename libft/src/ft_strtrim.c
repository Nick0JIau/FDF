/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:31:39 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/11/05 11:08:21 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcheck(char const *c)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(c);
	while (c[len - 1] == ' ' || c[len - 1] == '\t' || c[len - 1] == '\n')
		len--;
	while ((c[i] == ' ' || c[i] == '\t' || c[i] == '\n') && c[i])
	{
		i++;
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strcheck(s);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (len <= 0)
		return (ft_strdup(""));
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	s = s + i;
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	if (!str[i])
		str[i] = '\0';
	return (str);
}

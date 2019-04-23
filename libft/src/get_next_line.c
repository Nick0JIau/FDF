/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <akorobov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:28:13 by akorobov          #+#    #+#             */
/*   Updated: 2018/11/22 18:47:49 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int				join(char **buf, char **tmp)
{
	char		*tmp_for_free;

	tmp_for_free = ft_strjoin((*tmp), (*buf));
	ft_strdel(tmp);
	*tmp = ft_strdup(tmp_for_free);
	ft_strdel(&tmp_for_free);
	return (1);
}

void			create_line(char **line, char **tmp, char **adr_new_str)
{
	char		*tmp_for_free;

	if (*adr_new_str != NULL)
	{
		*line = ft_strsub((*tmp), 0, (*adr_new_str) - (*tmp));
		tmp_for_free = ft_strdup(*adr_new_str + 1);
		ft_strdel(tmp);
		*tmp = ft_strdup(tmp_for_free);
		ft_strdel(&tmp_for_free);
	}
	else if (ft_strlen(*tmp) > 0)
	{
		*line = ft_strdup(*tmp);
		ft_strdel(tmp);
	}
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buf;
	char		*adr_new_str;
	static char	*tmp[10240];

	READ(BUFF_SIZE);
	TEST(fd, line, (buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))));
	*line = NULL;
	TMP_NEW(tmp[fd]);
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 0)
	{
		JOIN(buf[ret], join(&buf, &tmp[fd]));
		if ((adr_new_str = ft_strchr(tmp[fd], '\n')) == NULL)
			while ((adr_new_str = ft_strchr(tmp[fd], '\n')) == NULL &&
					(ret = read(fd, buf, BUFF_SIZE)) != 0)
			{
				JOIN(buf[ret], join(&buf, &tmp[fd]));
			}
		create_line(line, &tmp[fd], &adr_new_str);
		ft_strdel(&buf);
		return ((RET(*line)));
	}
	ft_strdel(&buf);
	READ(ret);
	return ((RET(*line)));
}

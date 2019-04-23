/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:12:45 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/08 13:05:57 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_lstaddback(t_list **list, char const *content, size_t content_size)
{
	t_list	*newlist;
	t_list	*tmp;
	t_list	*start;

	tmp = *list;
	start = tmp;
	newlist = ft_lstnew(content, content_size);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = newlist;
	*list = start;
}

void	ft_dellst(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		free(tmp->content);
		free(tmp);
		tmp = tmp->next;
	}
}

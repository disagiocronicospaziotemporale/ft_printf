/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:19:21 by mriccard          #+#    #+#             */
/*   Updated: 2017/12/01 16:12:39 by mriccard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*tmp;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = (*f)(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	first = new;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:52:45 by kirilltruha       #+#    #+#             */
/*   Updated: 2020/11/11 10:58:20 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *first;
	t_list *new;

	new = lst;
	first = new;
	if (lst)
	{
		while (lst)
		{
			if ((new = ft_lstnew(f(lst->content))))
			{
				new->next = lst->next;
				lst = lst->next;
				new = new->next;
			}
			else
			{
				del(new->content);
				return (NULL);
			}
		}
		return (first);
	}
	return (NULL);
}
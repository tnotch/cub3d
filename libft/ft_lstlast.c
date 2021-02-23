/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:37:15 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/10 15:40:59 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *current;
	
	if (lst)
	{
		current = lst;
		while ((current->next))
			current = current->next;
		return (current);
	}
	return (NULL);
}
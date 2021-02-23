/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:49:06 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/10 20:37:53 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst && lst && del)
	{
		while(*lst)
		{
			ft_lstdelone(*lst, del);
			*lst = (*lst)->next;
		}			
	}
}
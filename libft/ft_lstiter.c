/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:38:37 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/10 20:47:39 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *current;

	current = lst;
	if (lst && f)
	{
		while (current)
		{
			f(current->content);
			current = current->next;
		}
	}
}
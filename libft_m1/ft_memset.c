/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:57:48 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/03 15:19:58 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *destination, int c, size_t n)
{
    size_t i;
    unsigned char *temp;

    i = 0;
    temp = destination;
    while (i < n)
    {
        temp[i] = c;
        i++;
    }
    return (destination);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:30:36 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/06 19:06:17 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char    *ft_strchr(const char *str, int ch)
{
    int i;

    i = 0;
    while (str[i] && str[i] != ch)
        i++;
    if (str[i] == ch)
        return ((char*)str + i);
    else
        return (NULL);
}

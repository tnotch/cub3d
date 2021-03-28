/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:35:56 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/05 16:51:40 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char *result;
    size_t i;

    i = 0;
    result = (char*)malloc(ft_strlen(s1) + 1);
    if (result == NULL)
        return (NULL);
    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}
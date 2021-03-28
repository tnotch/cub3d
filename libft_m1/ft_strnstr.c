/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:11 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/04 18:13:02 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    i = ft_strlen(haystack);
    j = ft_strlen(needle);
    if (j == 0)
        return ((char*)haystack);
    if (i < j)
        return (0);
    i = 0;
    while (i + j <= len && haystack)
    {
        if (*haystack == *needle)
        {
            if (0 == ft_strncmp(haystack, needle, j))
                return ((char*)haystack);   
        }
        haystack++;
        i++;
    }
    return (NULL);
}

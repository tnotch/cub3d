/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:46:32 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/08 15:26:13 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
    size_t  len;
    size_t  slen;
    len = 0;
    slen = ft_strlen(src);
    while (*dst && size > 0)
    {
        dst++;
        len++;
        size--;
    }
    while (*src && size-- > 1)
        *dst++ = *src++;
    if (size == 1 || *src == 0 || size == 0)
        *dst = '\0';
    return (slen + len);
}
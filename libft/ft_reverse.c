/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnotch <tnotch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:28:44 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/05 21:24:15 by tnotch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char    *ft_reverse(char *str)
{
    size_t i;
    size_t j;
    char c;

    i = 0;
    j = ft_strlen(str);
    while (i < j && str[i])
    {
        c =  str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
    return (str);
}

int main(void)
{
    char s[] = "Hello";
    char *d;
    d = ft_reverse("HELLO");
    printf("%s\n", s);
}
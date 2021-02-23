/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:26:36 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/09 15:14:59 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int ft_sofa(char const *s, char c);
static char *ft_mallocandfree(int size, char **result, int count);

char **ft_split(char const *s, char c)
{
    int i;
    int j;
	int soa;
    int lenstr;
    
    char **res;
    int arr;
    if (!s)
        return (NULL);
    if (!(res = (char**)malloc(sizeof(res) * ((soa = ft_sofa(s, c)) + 1))))
        return (NULL);
    i = 0;
    arr = 0;
    while (i < soa)
	{
        j = 0;
        lenstr = 0;
		while (s[arr] == c)
			arr++;  
        while (s[arr + lenstr] != c && s[arr + lenstr])
            lenstr++;
		if (!(res[i] = ft_mallocandfree(lenstr, res, i)))
			return (NULL);
        while (s[arr] != c && s[arr])
            res[i][j++] = s[arr++];
        res[i][j] = '\0';
        i++;          
    }
	res[i] = NULL;
    return ((char**)res);
}

static int ft_sofa(char const *s, char c)
{
    int res;
  
    res = 0;
    while (*s == c)
      s++;
    while (*s)
    {
		if (*s != c && *s)
		{
			res++;
			while (*s != c && *s)
				s++;
		}
		if (*s == c && *s)
		{
			while (*s == c && *s)
				s++;
		}
	}
	return (res);
}

static char *ft_mallocandfree(int size, char **result, int count)
{
	char *all;

	if (!(all = (char*)malloc(size)))
	{
		while (count > 0)
			free(result[count--]);
		free(result);	
		return (NULL);
	}
	else 
		return (all);
 }
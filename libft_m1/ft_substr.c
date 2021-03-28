/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:10:31 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/09 16:07:39 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t j;
	size_t i;
	char *res;
	
	j = 0;
	if (!s)
		return (0);
	i = ft_strlen(s);
	if (!(res = (char*)malloc(len + 1)))
		return (NULL);
	while (len-- > 0 && start < i)
		res[j++] = s[start++];
	res[j] = '\0';
	return (res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:03:17 by tnotch            #+#    #+#             */
/*   Updated: 2021/03/01 18:31:14 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*start;
	char	*start_s1;
	size_t	end;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	start_s1 = s1;
	end = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = (char*)malloc(end)))
		return (NULL);
	start = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	if (start_s1)
		free(start_s1);
	return (start);
}

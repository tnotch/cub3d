/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:41:21 by tnotch            #+#    #+#             */
/*   Updated: 2020/11/09 18:15:15 by kirilltruha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long long int num;
	char *res;
	int i;
	int j;
	int sign;
	
	i = 1;
	j = 0;
	sign = 0;
	num = n;
	if (n < 0)
	{
		i++;
		sign = 1;
		num = -num;
    }
	while ((n /= 10))
		i++;
	if (!(res = (char*)malloc(i + 1)))
		return (NULL);
	res[i--] = '\0';
	while (i >= sign)
	{
		res[i] =  num % 10 + '0';
		num = num / 10;
		i--;
	}
	if (sign != 0)
		res[j++] = '-';
	return (res) ;
}

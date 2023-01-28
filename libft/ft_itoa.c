/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:56:32 by averon            #+#    #+#             */
/*   Updated: 2022/11/29 12:22:18 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	calc_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n)
	{
		n = n / 10;
		size ++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nbr;
	ssize_t	size;

	nbr = n;
	if (n < 0)
		nbr = -nbr;
	size = calc_size(n);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	s[size--] = 0;
	if (n == 0)
		s[0] = '0';
	while (size >= 0 && nbr)
	{	
		s[size] = (nbr % 10 + 48);
		nbr = nbr / 10;
		size--;
	}	
	if (size == 0 && s[1])
		s[size] = '-';
	return (s);
}

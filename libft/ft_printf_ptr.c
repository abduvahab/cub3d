/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:45:29 by averon            #+#    #+#             */
/*   Updated: 2022/11/29 12:27:13 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_base(uintptr_t ptr, char *base)
{
	size_t	i;

	i = ft_strlen(base);
	if (ptr < i)
		ft_putchar_fd(base[ptr], 1);
	if (ptr >= i)
	{	
		ft_putptr_base(ptr / i, base);
		ft_putptr_base(ptr % i, base);
	}
}

int	ft_ptr_len(uintptr_t ptr)
{
	int	i;

	i = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}

int	ft_printf_ptr(uintptr_t ptr)
{
	int	printf_len;

	printf_len = write (1, "0x", 2);
	if (ptr == 0)
		printf_len = printf_len + 1;
	ft_putptr_base(ptr, "0123456789abcdef");
	printf_len += ft_ptr_len(ptr);
	return (printf_len);
}

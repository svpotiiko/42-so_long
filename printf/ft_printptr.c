/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:15:45 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/14 18:49:36 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putptr(unsigned long long num)
{
	long	a;
	char	*base1;
	char	*ab;

	base1 = "0123456789abcdef";
	a = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ab = (char *)malloc(sizeof(char) * ft_ptr_len(num));
	if (!ab)
		return ;
	while (num != 0)
	{
		if (num < 0)
			num = -num;
		ab[a] = base1[num % 16];
		num = num / 16;
		a++;
	}
	while (a--)
		ft_printchar(ab[a]);
	free(ab);
}

int	ft_printptr(unsigned long long num)
{
	write (1, "0x", 2);
	ft_putptr(num);
	return (ft_ptr_len(num) + 2);
}

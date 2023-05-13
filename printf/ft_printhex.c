/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:04:15 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/15 15:13:24 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
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

void	ft_puthex(unsigned int num)
{
	long	a;
	char	*base1;
	char	*ab;

	base1 = "0123456789abcdef";
	a = 0;
	if (!num)
	{
		ft_putchar('0');
		return ;
	}
	ab = (char *)malloc(sizeof(char) * ft_hex_len(num));
	if (!ab)
		return ;
	while (num != 0)
	{
		ab[a] = base1[num % 16];
		num = num / 16;
		a++;
	}
	while (a--)
		ft_putchar(ab[a]);
	free(ab);
}

int	ft_printhex(unsigned int num)
{
	ft_puthex(num);
	return (ft_hex_len(num));
}

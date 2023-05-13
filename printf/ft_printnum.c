/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:11:04 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/14 18:49:24 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

void	math(void)
{
	write(1, "-2147483648", 11);
	return ;
}

int	sign(int num)
{
	num = -num;
	write(1, "-", 1);
	return (num);
}

void	ft_putnum(int num)
{
	long	a;
	char	*ab;

	a = 0;
	if (num == 0)
		ft_putchar('0');
	if (num == -2147483648)
		return (math());
	ab = (char *)malloc(sizeof(char) * ft_num_len(num));
	if (!ab)
		return ;
	while (num != 0)
	{
		if (num < 0)
			num = sign(num);
		ab[a] = (num % 10) + '0';
		num = num / 10;
		a++;
	}
	while (a--)
		ft_printchar(ab[a]);
	free(ab);
}

int	ft_printnum(int num)
{
	ft_putnum(num);
	return (ft_num_len(num));
}

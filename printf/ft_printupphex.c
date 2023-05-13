/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printupphex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:05:24 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/15 15:11:10 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upphex_len(unsigned int num)
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

void	ft_putupphex(unsigned int num)
{
	long	a;
	char	*base2;
	char	*ab;

	base2 = "0123456789ABCDEF";
	a = 0;
	if (!num)
	{
		ft_putchar('0');
		return ;
	}
	ab = (char *)malloc(sizeof(char) * ft_upphex_len(num));
	if (!ab)
		return ;
	while (num != 0)
	{
		ab[a] = base2[num % 16];
		num = num / 16;
		a++;
	}
	while (a--)
		ft_putchar(ab[a]);
	free(ab);
}

int	ft_printupphex(unsigned int num)
{
	ft_putupphex(num);
	return (ft_upphex_len(num));
}

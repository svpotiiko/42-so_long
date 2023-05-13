/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:37:13 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/14 18:49:57 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unnum_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

void	ft_unputnum(unsigned int num)
{
	long	a;
	char	*ab;

	a = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ab = (char *)malloc(sizeof(char) * ft_num_len(num));
	if (!ab)
		return ;
	while (num != 0)
	{
		ab[a] = (num % 10) + '0';
		num = num / 10;
		a++;
	}
	while (a--)
		ft_printchar(ab[a]);
	free(ab);
}

int	ft_printunnum(unsigned int num)
{
	ft_unputnum(num);
	return (ft_unnum_len(num));
}

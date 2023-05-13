/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:23:21 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/15 15:11:32 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_form(va_list args, int form)
{
	int	print_len;

	print_len = 0;
	if (form == 'c')
		print_len += ft_printchar(va_arg(args, int));
	else if (form == 's')
		print_len += ft_printstr(va_arg(args, char *));
	else if (form == 'p')
		print_len += ft_printptr(va_arg(args, unsigned long long));
	if (form == 'd' || form == 'i')
		print_len += ft_printnum(va_arg(args, int));
	if (form == 'u')
		print_len += ft_printunnum(va_arg(args, unsigned int));
	if (form == 'x')
		print_len += ft_printhex(va_arg(args, unsigned int));
	if (form == 'X')
		print_len += ft_printupphex(va_arg(args, unsigned int));
	if (form == '%')
		print_len += ft_printper();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		a;
	va_list	args;
	int		print_len;

	a = 0;
	print_len = 0;
	va_start(args, str);
	while (str[a])
	{
		if (str[a] == '%')
		{
			a++;
			print_len += ft_form(args, str[a]);
		}
		else
			print_len += ft_printchar(str[a]);
		a++;
	}
	va_end(args);
	return (print_len);
}

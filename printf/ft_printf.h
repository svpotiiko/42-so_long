/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:53:34 by vpotiiko          #+#    #+#             */
/*   Updated: 2022/11/15 15:11:22 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_form(va_list args, int form);
int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int		ft_printstr(char *str);
void	ft_putchar(int c);
void	ft_putstr(char *str);
int		ft_printptr(unsigned long long num);
int		ft_unnum_len(unsigned int num);
int		ft_printunnum(unsigned int num);
void	ft_unputnum(unsigned int num);
int		ft_num_len(int num);
void	ft_putnum(int num);
int		ft_printnum(int num);
int		ft_printhex(unsigned int num);
int		ft_hex_len(unsigned int num);
int		ft_hexx_len(unsigned int num);
void	ft_puthex(unsigned int num);
int		ft_printper(void);
int		ft_printupphex(unsigned int num);
void	ft_putupphex(unsigned int num);
int		ft_upphex_len(unsigned int num);
void	math(void);
int		sign(int num);

#endif
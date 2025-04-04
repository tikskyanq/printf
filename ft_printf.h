/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamalya <tkamalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:10:31 by tkamalya          #+#    #+#             */
/*   Updated: 2025/03/20 15:37:02 by tkamalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_write_lower_x(unsigned int n, int *count);
void	ft_write_up_x(unsigned long n, int *count);
void	ft_write_ptr(unsigned long n, int *count);
void	ft_putunsignednbr(unsigned int n, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putchar(char c, int *count);
void	ft_handle_string(char *str, int *count);
int		ft_handle_format(const char **format, va_list args, int *count);
void	ft_handle_pointer(unsigned long ptr, int *count);

#endif
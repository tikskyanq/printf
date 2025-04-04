/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamalya <tkamalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:23:14 by tkamalya          #+#    #+#             */
/*   Updated: 2025/03/20 15:32:45 by tkamalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_lower_x(unsigned int n, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_write_lower_x(n / 16, count);
	ft_putchar(hex[n % 16], count);
}

void	ft_write_up_x(unsigned long n, int *count)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_write_up_x(n / 16, count);
	ft_putchar(hex[n % 16], count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			format += ft_handle_format(&format, args, &count) - 1;
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}

int	ft_handle_format(const char **format, va_list args, int *count)
{
	(*format)++;
	if (**format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (**format == 's')
		ft_handle_string(va_arg(args, char *), count);
	else if (**format == 'd' || **format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (**format == 'u')
		ft_putunsignednbr(va_arg(args, unsigned int), count);
	else if (**format == 'p')
		ft_handle_pointer(va_arg(args, unsigned long), count);
	else if (**format == 'x')
		ft_write_lower_x(va_arg(args, unsigned int), count);
	else if (**format == 'X')
		ft_write_up_x(va_arg(args, unsigned int), count);
	else if (**format == '%')
		ft_putchar('%', count);
	return (1);
}

void	ft_handle_string(char *str, int *count)
{
	if (!str)
	{
		*count += 6;
		write(1, "(null)", 6);
	}
	else
		ft_putstr(str, count);
}

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		count;
// 	char	*str;

// 	count = 0;
// 	va_start(args, format);
// 	while (*format)
// 	{
// 		if (*format == '%' && *(format +1))
// 		{
// 			format++;
// 			if (*format == 'c')
// 				ft_putchar(va_arg(args, int), &count);
// 			else if (*format == 's')
// 			{

// 				str = va_arg(args, char *);
// 				if (!str)
// 				{
// 					count += 6;
// 					write(1, "(null)", 6);
// 					continue ;
// 				}
// 				ft_putstr(str, &count);
// 			}
// 			else if (*format == 'd' || *format == 'i')
// 				ft_putnbr(va_arg(args, int), &count);
// 			else if (*format == 'u')
// 				ft_putunsignednbr(va_arg(args,unsigned int), &count);
// 			else if (*format == 'p')
// 			{
// 				write(1, "0x", 2);
// 				count += 2;
// 				ft_write_ptr(va_arg(args, unsigned long), &count);
// 			}
// 			else if (*format == 'x')
// 				ft_write_lower_x(va_arg(args, unsigned int), &count);
// 			else if (*format == 'X')
// 				ft_write_up_x(va_arg(args, unsigned int), &count);
// 			else if (*format == '%')
// 			{
// 				write(1, "%", 1);
// 				count++;
// 			}
// 		}
// 		else
// 			ft_putchar(*format, &count);
// 		format++;
// 	}
// 	va_end(args);
// 	return (count);
// }
/*
int main()
{
	char *c = "Tiks";
	int a = 4; 
	ft_printf("meri qanaky->%d\n", ft_printf("mery->%X\n",1245));
	// ft_printf("%d\n", count);
	printf("%d\n",printf("dzer->%X\n",1245));
}*/
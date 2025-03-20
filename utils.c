/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamalya <tkamalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:22:00 by tkamalya          #+#    #+#             */
/*   Updated: 2025/03/19 00:26:57 by tkamalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *s, int *count)
{
	while (*s)
		ft_putchar(*s++, count);
}

void	ft_putnbr(int n, int *count)
{
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	ft_putchar((n % 10) + '0', count);
}

void	ft_putunsignednbr(int n, int *count)
{
	if (n >= 10)
		ft_putunsignednbr(n / 10, count);
	ft_putunsignednbr((n % 10) + '0', count);
}

void	ft_write_ptr(unsigned long n, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_write_ptr(n / 16, count);
	ft_putchar(hex[n % 16], count);
}

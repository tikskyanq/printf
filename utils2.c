/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamalya <tkamalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:26:47 by tkamalya          #+#    #+#             */
/*   Updated: 2025/03/20 15:37:33 by tkamalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_pointer(unsigned long ptr, int *count)
{
	write(1, "0x", 2);
	*count += 2;
	ft_write_ptr(ptr, count);
}

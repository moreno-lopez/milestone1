/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horarivo <horarivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 06:29:23 by horarivo'         #+#    #+#             */
/*   Updated: 2026/02/14 08:10:41 by horarivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_long(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex_long(nbr / 16, base);
	count += ft_putchar(base[(nbr % 16)]);
	return (count);
}

int	ft_putaddr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	count = ft_putstr("0x");
	count += ft_puthex_long(addr, "0123456789abcdef");
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horarivo <horarivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 06:52:35 by horarivo'         #+#    #+#             */
/*   Updated: 2026/02/14 07:32:45 by horarivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

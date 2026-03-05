/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horarivo <horarivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:09:12 by horarivo          #+#    #+#             */
/*   Updated: 2026/02/16 09:09:25 by horarivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putaddr(void *ptr);
int	ft_putstr(char *s);
int	ft_puthex(unsigned int n, char *base);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:44:21 by youbella          #+#    #+#             */
/*   Updated: 2024/12/06 12:08:09 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_add(unsigned long nb)
{
	int		len;
	short	i;
	char	*hex;
	char	buffer[16];

	len = 0;
	i = 0;
	hex = "0123456789abcdef";
	if (nb == 0)
		return (ft_putstr("0x0"));
	len += ft_putstr("0x");
	while (nb != 0)
	{
		buffer[i++] = hex[nb % 16];
		nb /= 16;
	}
	i--;
	while (i >= 0)
		len += ft_putchar(buffer[i--]);
	return (len);
}
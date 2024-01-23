/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:52:01 by pollivie          #+#    #+#             */
/*   Updated: 2023/11/03 17:52:01 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

int	uputnbr_base(uint64_t num, char *base, int radix)
{
	int		i;
	int		len;
	char	result[64];

	len = 0;
	if (num < 0)
	{
		len += write(1, "-", 1);
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		result[i] = base[num % radix];
		num /= radix;
		i++;
	}
	if (i == 0)
		len += write(1, "0", 1);
	else
	{
		while (i > 0)
			len += write(1, &result[--i], 1);
	}
	return (len);
}

int	iputnbr_base(int64_t num, char *base, int radix)
{
	int		i;
	int		len;
	char	result[64];

	len = 0;
	if (num < 0)
	{
		len += write(1, "-", 1);
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		result[i] = base[num % radix];
		num /= radix;
		i++;
	}
	if (i == 0)
		len += write(1, "0", 1);
	else
	{
		while (i > 0)
			len += write(1, &result[--i], 1);
	}
	return (len);
}

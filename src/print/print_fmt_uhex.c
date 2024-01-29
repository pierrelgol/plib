/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_uhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:50:14 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/08 09:18:27 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	print_fmt_uhex(va_list *arg)
{
	uint32_t	lhex;

	lhex = va_arg(*arg, uint32_t);
	return (uputnbr_base((uint32_t)lhex, "0123456789ABCDEF", 16));
}

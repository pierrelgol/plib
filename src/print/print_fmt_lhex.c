/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_lhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:49:38 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/08 09:17:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	print_fmt_lhex(va_list *arg)
{
	uint32_t	lhex;

	lhex = va_arg(*arg, uint32_t);
	return (uputnbr_base((uint32_t)lhex, "0123456789abcdef", 16));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:49:52 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/08 09:18:12 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

int	print_fmt_str(va_list *arg)
{
	char	*str;

	str = va_arg(*arg, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, string_length(str)));
}

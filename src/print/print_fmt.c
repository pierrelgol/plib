/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:03:20 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/08 09:17:46 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/plib.h"

int	print_fmt(const char *fmt, ...)
{
	int		count;
	va_list	args;
	t_fsm	fsm;

	count = 0;
	va_start(args, fmt);
	fsm = fsm_init(fmt);
	while (*fsm.fmt)
	{
		fsm.curr = fsm.get_curr_state(fsm.curr, *fsm.fmt);
		fsm.use_print_fmt = fsm.get_print_fmt(fsm.curr);
		if (fsm.curr == FSM_PRINT_CHAR)
			count += fsm.use_print_fmt((va_list *)fsm.fmt);
		else
			count += (fsm.use_print_fmt(&args));
		fsm.fmt++;
	}
	va_end(args);
	return (count);
}

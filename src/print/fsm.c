/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:35:35 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/08 09:17:39 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

static t_print_fmt	g_dispatch_table[32];

struct s_fsm	fsm_init(const char *fmt)
{
	t_fsm	self;

	self.count = 0;
	self.fmt = fmt;
	self.curr = FSM_START;
	self.get_curr_state = fsm_interpret;
	self.get_print_fmt = fsm_dispatch;
	g_dispatch_table[FSM_LOOK_FOR_FMT] = fsm_eat_char;
	g_dispatch_table[FSM_PRINT_CHAR] = fsm_put_char;
	g_dispatch_table[FSM_FOUND_FMT_I8] = print_fmt_i8;
	g_dispatch_table[FSM_FOUND_FMT_I32] = print_fmt_i32;
	g_dispatch_table[FSM_FOUND_FMT_U32] = print_fmt_u32;
	g_dispatch_table[FSM_FOUND_FMT_LHEX] = print_fmt_lhex;
	g_dispatch_table[FSM_FOUND_FMT_UHEX] = print_fmt_uhex;
	g_dispatch_table[FSM_FOUND_FMT_STR] = print_fmt_str;
	g_dispatch_table[FSM_FOUND_FMT_PTR] = print_fmt_ptr;
	return (self);
}

int	fsm_eat_char(va_list *arg)
{
	(void)arg;
	return (0);
}

int	fsm_put_char(va_list *arg)
{
	return (write(1, arg, 1));
}

enum e_state	fsm_interpret(enum e_state prev, int ch)
{
	if (ch == '\0' || prev == FSM_STOP)
		return (FSM_STOP);
	else if (prev == FSM_LOOK_FOR_FMT && ch == '%')
		return (FSM_PRINT_CHAR);
	else if (prev != FSM_LOOK_FOR_FMT && ch == '%')
		return (FSM_LOOK_FOR_FMT);
	else if (prev == FSM_LOOK_FOR_FMT && ch == 'c')
		return (FSM_FOUND_FMT_I8);
	else if (prev == FSM_LOOK_FOR_FMT && (ch == 'i' || ch == 'd'))
		return (FSM_FOUND_FMT_I32);
	else if (prev == FSM_LOOK_FOR_FMT && ch == 'u')
		return (FSM_FOUND_FMT_U32);
	else if (prev == FSM_LOOK_FOR_FMT && ch == 'x')
		return (FSM_FOUND_FMT_LHEX);
	else if (prev == FSM_LOOK_FOR_FMT && ch == 'X')
		return (FSM_FOUND_FMT_UHEX);
	else if (prev == FSM_LOOK_FOR_FMT && ch == 's')
		return (FSM_FOUND_FMT_STR);
	else if (prev == FSM_LOOK_FOR_FMT && ch == 'p')
		return (FSM_FOUND_FMT_PTR);
	else
		return (FSM_PRINT_CHAR);
}

t_print_fmt	fsm_dispatch(enum e_state curr)
{
	return (g_dispatch_table[curr]);
}

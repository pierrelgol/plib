/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_count_until.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:48:44 by pollivie          #+#    #+#             */
/*   Updated: 2024/01/29 14:48:45 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/plib.h"

unsigned int string_count_until(char *str, int ch)
{
	unsigned int count;

	if (!str)
		return (0);
	count = 0;
	while (str[count]){
		if (str[count] == ch)
			return (count);
		++count;
	}
	return (count);
}


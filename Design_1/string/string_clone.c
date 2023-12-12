/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:18:07 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/10 20:18:09 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	*string_clone(char *str)
{
	char			*result;
	unsigned int	rlen;

	rlen = string_length(str);
	result = string_create(rlen + 1);
	string_copy(result, str, rlen);
	return (result);
}

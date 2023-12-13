/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:04:25 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:04:26 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

void	*memory_clone(void *m1, unsigned int n)
{
	const char	*ptr_m1;
	char		*result;
	int			i;

	if (!m1 || !n)
		return (0);
	ptr_m1 = m1;
	result = memory_alloc(n + 1, sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (n--)
		result[i++] = *ptr_m1++;
	return (result);
}

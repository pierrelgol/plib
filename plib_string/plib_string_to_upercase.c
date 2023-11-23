/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_to_upercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:39:57 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:06:05 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*plib_string_to_upercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 'a') + 'A';
		++i;
	}
	return (str);
}

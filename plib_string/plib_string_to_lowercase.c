/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_to_lowercase.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:39:49 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 11:05:57 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*plib_string_to_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'A') + 'a';
		++i;
	}
	return (str);
}

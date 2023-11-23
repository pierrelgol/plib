/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_compare.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:37:18 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:37:20 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	plib_string_compare(char *str1, char *str2, unsigned int cmpsize)
{
	char	*ptr_s1;
	char	*ptr_s2;

	ptr_s1 = str1;
	ptr_s2 = str2;
	if (cmpsize == 0)
		return (0);
	while (--cmpsize && *ptr_s1 && *ptr_s1 == *ptr_s2)
	{
		++ptr_s1;
		++ptr_s2;
	}
	return ((unsigned char)*ptr_s1 - *ptr_s2);
}

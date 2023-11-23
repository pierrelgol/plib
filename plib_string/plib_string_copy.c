/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:38:55 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 10:19:23 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*plib_string_copy(char *dest, char *src, unsigned int cpysize)
{
	unsigned int	index;

	index = 0;
	while (src[index] && index < cpysize)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < cpysize)
		dest[index++] = '\0';
	return (dest);
}

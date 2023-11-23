/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plib_string_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:34:14 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/23 09:34:16 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

char	**split_error_cleanup(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	split_get_word_count(char *str, char *set)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && set[(int)*str] == 1)
			str++;
		if (*str && set[(int)*str] != 1)
		{
			count++;
			while (*str && set[(int)*str] != 1)
				str++;
		}
	}
	return (count);
}

static char	*split_make_word(char *str, char *set)
{
	char	*word;
	int		wlen;

	wlen = 0;
	while (str[wlen] && set[(int)str[wlen]] != 1)
		++wlen;
	word = malloc(sizeof(char) * (wlen + 1));
	if (!word)
		return (NULL);
	word = plib_string_copy(word, str, wlen);
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*set;
	int		word_count;
	int		index;

	set = plib_char_boolset_create_from((char [255]){0}, charset);
	word_count = split_get_word_count(str, set);
	result = plib_memory_alloc(word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	while (*str)
	{
		while (*str && set[(int)*str] == 1)
			str++;
		if (*str && set[(int)*str] != 1)
			result[index] = split_make_word(str, charset);
		if (!result[index])
			return (split_error_cleanup(result, index));
		++index;
		while (*str && set[(int)*str] != 1)
			str++;
	}
	return (result);
}

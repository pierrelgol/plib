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

static char	**split_error_cleanup(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
		plib_memory_dealloc(tab[i++]);
	plib_memory_dealloc(tab);
	return (NULL);
}

static int	split_get_word_count(char *str, char *set)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && set[(unsigned int)*str] == 1)
			++str;
		while (*str && set[(unsigned int)*str] == 0)
			++str;
		if (set[(unsigned int)*(str - 1)] != 1)
			++words;
	}
	return (words);
}

static char	*split_make_word(char *str, char *set)
{
	char	*word;
	int		wlen;

	wlen = 0;
	while (str[wlen] && set[(int)str[wlen]] != 1)
		++wlen;
	word = plib_memory_alloc(sizeof(char), (wlen + 1));
	if (!word)
		return (NULL);
	word = plib_string_copy(word, str, wlen);
	return (word);
}

char	**plib_string_split(char *str, char *charset)
{
	char	**result;
	char	*set;
	int		word_count;
	int		index;

	set = plib_char_boolset_create_from((char[255]){0}, charset);
	word_count = split_get_word_count(str, set);
	result = plib_memory_alloc(word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	while (*str)
	{
		while (*str && set[(unsigned int)*str] == 1)
			++str;
		if (*str && set[(unsigned int)*str] == 0)
			result[index++] = split_make_word(str, set);
		if (!result[index - 1])
			return (split_error_cleanup(result, index - 1));
		while (*str && set[(unsigned int)*str] == 0)
			++str;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split_charset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:52:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:52:03 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static unsigned int	split_words_count(char *str, char *set)
{
	unsigned int	words;

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

static char	*split_word_create(char *str, char *set)
{
	unsigned int	wlen;
	char			*word;

	wlen = 0;
	while (str[wlen] && set[(int)str[wlen]] != 1)
		++wlen;
	word = string_create((wlen + 1));
	if (!word)
		return (0);
	word = string_ncopy(word, str, wlen);
	return (word);
}

char	**string_split_charset(char *str, char *charset)
{
	char			**result;
	char			*set;
	unsigned int	word_count;
	unsigned int	index;

	set = string_to_boolset((char [255]){0}, charset);
	word_count = split_words_count(str, set);
	result = string_split_create(word_count + 1);
	if (!result)
		return (0);
	index = 0;
	while (*str)
	{
		while (*str && set[(unsigned int)*str] == 1)
			++str;
		if (*str && set[(unsigned int)*str] == 0)
			result[index++] = split_word_create(str, set);
		if (!result[index - 1])
			return (string_split_destroy(result, index - 1));
		while (*str && set[(unsigned int)*str] == 0)
			++str;
	}
	return (result);
}

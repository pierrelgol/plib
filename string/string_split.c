/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:51:35 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/01 12:51:36 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static unsigned int	split_words_count(char *str, int ch)
{
	unsigned int	words;

	words = 0;
	while (*str)
	{
		while (*str && *str == ch)
			++str;
		while (*str && *str != ch)
			++str;
		if (*(str - 1) != ch)
			++words;
	}
	return (words);
}

static char	*split_word_create(char *str, int ch)
{
	unsigned int	wlen;
	char			*word;

	wlen = 0;
	while (str[wlen] && str[wlen] != ch)
		++wlen;
	word = string_create((wlen + 1));
	if (!word)
		return (0);
	word = string_ncopy(word, str, wlen);
	return (word);
}

char	**string_split(char *str, int ch)
{
	char			**result;
	unsigned int	length;
	unsigned int	index;

	index = 0;
	length = split_words_count(str, ch);
	result = string_split_create(length + 1);
	if (!result)
		return (0);
	while (*str)
	{
		while (*str && *str == ch)
			++str;
		if (*str && *str != ch)
			result[index++] = split_word_create(str, ch);
		if (!result[index - 1])
			return (string_split_destroy(result, index - 1));
		while (*str && *str != ch)
			++str;
	}
	return (result);
}

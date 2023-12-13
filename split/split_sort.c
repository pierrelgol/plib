/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:00:39 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/12/12 10:00:40 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../plib.h"

static void	split_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	split_sort_partition(char **split, int low, int high)
{
	char	*pivot;
	int		i;
	int		j;

	i = low - 1;
	j = low;
	pivot = split[high];
	while (j < high)
	{
		if (string_compare(split[j], pivot) <= 0)
		{
			++i;
			split_swap(&split[i], &split[j]);
		}
		++j;
	}
	split_swap(&split[i + 1], &split[high]);
	return (i + 1);
}

static void	split_sort_large(char **split, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = split_sort_partition(split, low, high);
		split_sort_large(split, low, pivot_index - 1);
		split_sort_large(split, pivot_index + 1, high);
	}
}

static void	split_sort_small(char **split)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (split[i])
	{
		j = i;
		while (j > 0 && string_compare(split[j - 1], split[j]) <= 0)
		{
			split_swap(&split[j - 1], &split[j]);
			--j;
		}
		++i;
	}
}

char	**split_sort(char **split)
{
	unsigned int	size;

	if (!split)
		return (0);
	size = split_size(split);
	if (size < 2)
		return (split);
	else if (size <= 32)
		split_sort_small(split);
	else
		split_sort_large(split, 0, size);
	return (split);
}

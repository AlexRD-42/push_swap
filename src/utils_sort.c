/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:45:52 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/08 12:58:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "push_swap.h"

void    ft_find_lis(int32_t *array, size_t length, int32_t *lis_out, size_t *len_out)
{
	size_t	i;
	size_t	j;
	int32_t	max_lis[MAX_SIZE];
	int32_t	prev[MAX_SIZE];
	size_t 	best_end = 0;
	size_t	best_len = 1;

	for (i = 0; i < length; ++i)
	{
		max_lis[i] = 1;
		prev[i] = -1;
		for (j = 0; j < i; ++j)
			if (array[j] < array[i] && max_lis[j] + 1 > max_lis[i])
			{
				max_lis[i] = max_lis[j] + 1;
				prev[i] = j;
			}
		if ((size_t)max_lis[i] > best_len)
		{
			best_len = max_lis[i];
			best_end = i;
		}
	}
	size_t k = best_end;
	for (i = best_len; i-- > 0; k = prev[k])
		lis_out[i] = array[k];
	*len_out = best_len;
}

size_t	ft_get_entropy(t_stack *sta, t_stack *stb)
{
	size_t	i;
	size_t	j;
	size_t	total_entropy;

	i = 0;
	j = 0;
	total_entropy = 0;
	while (i < sta->length)
	{
		total_entropy += i64_absdiff(i, sta->bot[i]);
		i++;
	}
	j = stb->length;
	while (j > 0)
	{
		total_entropy += i64_absdiff(i, stb->bot[j - 1]);
		j--;
		i++;
	}
	return (total_entropy);
}

t_med	ft_get_median(int32_t *array, size_t length, uint8_t *lut)
{
	t_med	med;
	int32_t	min;
	int32_t	max;
	size_t	i;

	i = 0;
	min = INT32_MAX;
	max = 0;
	while (i < length)
	{
		if (lut[array[i]] == 0 && array[i] < min)
			min = array[i];
		if (lut[array[i]] == 0 && array[i] > max)
			max = array[i];
		i++;
	}
	med.middle = min + (max - min) / 2;
	med.lower = min + (max - min) / 4;
	med.upper = max - (max - min) / 4;
	return (med);
}

void	ft_insertion_sort(int32_t *array, size_t length)
{
	size_t	i;
	size_t	j;
	int32_t	key;

	i = 1;
	while (i < length)
	{
		j = i;
		key = array[i];
		while (j > 0 && array[j - 1] > key)
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = key;
		i++;
	}
}

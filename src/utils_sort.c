/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:45:52 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 13:07:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "push_swap.h"

static
size_t	build_lis(t_stack *sta, uint8_t *lut, int32_t *lis, int32_t *prev)
{
	const size_t	best_end = ft_get_max_index(lis, sta->length);
	size_t			lis_length;
	size_t			j;

	j = best_end;
	lis_length = lis[best_end];
	ft_memset(lut, 0, MAX_SIZE * sizeof(uint8_t));
	while (lis_length > 0)
	{
		lut[sta->bot[j]] = 1;
		j = prev[j];
		lis_length--;
	}
	return (lis[best_end]);
}

size_t	ft_find_lis(t_stack *sta, uint8_t *lut)
{
	size_t	i;
	size_t	j;
	int32_t	max_lis[MAX_SIZE];
	int32_t	prev[MAX_SIZE];

	i = 0;
	while (i < sta->length)
	{
		max_lis[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (sta->bot[j] < sta->bot[i] && max_lis[j] + 1 > max_lis[i])
			{
				max_lis[i] = max_lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
	return (build_lis(sta, lut, max_lis, prev));
}

t_med	ft_get_median(int32_t *array, size_t length, uint8_t *lut)
{
	t_med	med;
	int32_t	min;
	int32_t	max;
	size_t	i;

	i = 0;
	min = INT32_MAX;
	max = INT32_MIN;
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

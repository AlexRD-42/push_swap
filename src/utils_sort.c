/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:45:52 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/03 16:43:44 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "push_swap.h"

t_median	ft_get_median(int32_t *array, size_t start, size_t end)
{
	t_median	median;
	size_t		length;

	length = end - start;
	median.count = length / 2 + (length % 2 != 0);
	length -= (end != start);
	array += start;
	median.lower = *(array + length / 4);
	median.middle = *(array + length / 2 + (length % 2 != 0));
	median.upper = *(array + length - length / 4);
	return (median);
}

t_median	ft_get_median2(size_t start, size_t end)
{
	t_median	median;
	size_t		length;

	length = end - start;
	median.count = length / 2;
	median.lower = start + length / 4;
	median.middle = start + length / 2;
	median.upper = end - length / 4;
	return (median);
}

int64_t	ft_delta_sum(int32_t *array, size_t length)
{
	size_t	i;
	int64_t	sum;

	sum = 0;
	i = 0;
	while (i < length / 2)
	{
		sum += array[i];
		i++;
	}
	i += (length & 1);
	while (i < length)
	{
		sum -= array[i];
		i++;
	}
	return (sum);
}

// Need to implement a is_circular_sorted
int64_t	ft_delta_count(int32_t *array, size_t length)
{
	size_t	i;
	int64_t	count;

	count = 0;
	i = 1;
	while (i < length / 2)
	{
		count += array[i - 1] > array[i];
		i++;
	}
	i += (length & 1);
	while (i < length)
	{
		count -= array[i - 1] > array[i];
		i++;
	}
	return (count);
}

uint8_t	ft_sort_status(t_stack *sta, t_stack *stb)
{
	uint8_t	status;
	size_t	i;

	i = 1;
	status = 0;
	while (i < sta->length)
	{
		if (sta->bot[i - 1] > sta->bot[i])
		{
			status += 1;
			break ;
		}
		i++;
	}
	i = 1;
	while (i < stb->length)
	{
		if (stb->bot[i - 1] < stb->bot[i])
		{
			status += 2;
			break ;
		}
		i++;
	}
	return (status);
}

void	ft_shuffle(int32_t *array, size_t size, int32_t seed)
{
	int32_t	temp;
	size_t	j;

	srand(seed);
	while (size > 0)
	{
		size--;
		j = rand() % (size + 1);
		temp = array[size];
		array[size] = array[j];
		array[j] = temp;
	}
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

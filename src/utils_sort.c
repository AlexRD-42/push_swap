/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:45:52 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/23 12:51:48 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "push_swap.h"

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

t_median	ft_get_median(int32_t *array, size_t length)
{
	t_median		median;

	ft_selection_sort(array, length);
	if (length-- == 0)
		return (median);
	median.a = *(array + length / 4);
	median.mid = *(array + length / 2);
	median.b = *(array + length - length / 4);
	return (median);
}

size_t	ft_sort_status(t_stack *sta, t_stack *stb)
{
	size_t	i;

	i = 1;
	while (i < sta->length)
	{
		if (sta->bot[i - 1] > sta->bot[i])
			return (sta->length - i - 1);
		i++;
	}
	i = 1;
	while (i < stb->length)
	{
		if (stb->bot[i - 1] < stb->bot[i])
			return (stb->length - i - 1);
		i++;
	}
	return (0);
}

void	ft_selection_sort(int32_t *array, size_t length)
{
	int32_t			temp;
	int32_t			*min;
	int32_t			*ptr;
	const int32_t	*end = array + length;

	while (array < end - 1)
	{
		min = array;
		ptr = array + 1;
		while (ptr < end)
		{
			if (*ptr < *min)
				min = ptr;
			ptr++;
		}
		temp = *array;
		*array = *min;
		*min = temp;
		array++;
	}
}
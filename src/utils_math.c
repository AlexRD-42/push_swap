/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:48:42 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/05 11:36:27 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

size_t	get_entropy(t_stack *sta, t_stack *stb)
{
	size_t	i;
	size_t	j;
	size_t	total_entropy;

	i = 0;
	j = 0;
	total_entropy = 0;
	while (i < sta->length)
	{
		total_entropy += i32_abs_diff(i, sta->bot[i]);
		i++;
	}
	j = stb->length;
	while (j > 0)
	{
		total_entropy += i32_abs_diff(i, stb->bot[j - 1]);
		j--;
		i++;
	}
	return (total_entropy);
}

int32_t	i32_abs_diff(int32_t number1, int32_t number2)
{
	if (number1 >= number2)
		return (number1 - number2);
	else
		return (number2 - number1);
}

int32_t	i32_abs(int32_t number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

size_t	ft_get_min_index(int32_t *array, size_t length)
{
	size_t	i;
	size_t	min;

	min = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] < array[min])
			min = i;
		i++;
	}
	return (min);
}

size_t	ft_get_max_index(int32_t *array, size_t length)
{
	size_t	i;
	size_t	max;

	max = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] > array[max])
			max = i;
		i++;
	}
	return (max);
}


int32_t	i32_minrange(const int32_t *number, const size_t length)
{
	int32_t	min;
	size_t	i;

	min = *number;
	i = 1;
	while (i < length)
	{
		if (number[i] < min)
			min = number[i];
		i++;
	}
	return (min);
}

int32_t	i32_maxrange(const int32_t *number, const size_t length)
{
	int32_t	max;
	size_t	i;

	max = *number;
	i = 1;
	while (i < length)
	{
		if (number[i] > max)
			max = number[i];
		i++;
	}
	return (max);
}

int32_t	i32_min(int32_t number1, int32_t number2)
{
	if (number1 <= number2)
		return (number1);
	else
		return (number2);
}

int32_t	i32_max(int32_t number1, int32_t number2)
{
	if (number1 >= number2)
		return (number1);
	else
		return (number2);
}

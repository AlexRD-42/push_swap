/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:48:42 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/08 11:03:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

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

int64_t	i64_abs(int64_t number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

int64_t	i64_min(int64_t number1, int64_t number2)
{
	if (number1 <= number2)
		return (number1);
	else
		return (number2);
}

int64_t	i64_max(int64_t number1, int64_t number2)
{
	if (number1 >= number2)
		return (number1);
	else
		return (number2);
}

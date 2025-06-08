/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:48:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/08 20:22:29 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

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

int64_t	i64_abs(int64_t number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

int64_t	i64_absdiff(int64_t number1, int64_t number2)
{
	if (number1 >= number2)
		return (number1 - number2);
	else
		return (number2 - number1);
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

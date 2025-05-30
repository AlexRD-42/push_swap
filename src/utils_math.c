/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:48:42 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/30 12:24:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

int32_t	i32_abs(int32_t number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

int32_t	i32_minrange(const int32_t *number, size_t length)
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

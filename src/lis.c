/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:00:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/06 10:00:22 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

void    ft_find_lis(int32_t *array, size_t length, int32_t *lis_out, size_t *len_out)
{
	size_t	i;
	size_t	j;
	int32_t	max_lis[1024];
	int32_t	prev[1024];
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

void    ft_find_lis2(int32_t *array, size_t length, int32_t *lis_out, size_t *len_out)
{
	size_t	i;
	size_t	j;
	int32_t	max_lis[1024];
	int32_t	prev[1024];
	size_t 	best_end = 0;
	size_t	best_len = 1;

	for (i = 0; i < length; ++i)
	{
		max_lis[i] = 1;
		prev[i] = -1;
		for (j = 0; j < i; ++j)
			if (array[j] > array[i] && max_lis[j] + 1 > max_lis[i])
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
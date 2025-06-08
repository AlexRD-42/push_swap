/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:34:01 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/06 09:41:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15
// 0, 2, 6, 9, 11, 15
void    ft_find_lis(int32_t array[16], size_t length, int32_t *lis_out, size_t *len_out)
{
	size_t	i;
	size_t	j;
	int32_t	max_lis[16];
	int32_t	prev[16];
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

int main()
{
	int32_t	array[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	size_t	length = 16;
	int32_t	lis[16];
	size_t	lis_len;

	ft_find_lis(array, length, lis, &lis_len);
}
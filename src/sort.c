/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/08 20:18:27 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

static
void	finish_rotate(t_stack *sta, t_stack *stb)
{
	if (sta->bot[0] >= (int32_t) sta->length / 2)
	{
		while (sta->bot[0] != 0)
			ft_command("rra", sta, stb);
	}
	else
	{
		while (sta->bot[0] != 0)
			ft_command("ra", sta, stb);
	}
}

static
void	flip_order(int32_t *array, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		array[i] = length - 1 - array[i];
		i++;
	}
}

void	ft_initialize(t_stack *sta, t_stack *stb, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	ft_memcpy(stb->bot, sta->bot, length * sizeof(int32_t));
	ft_insertion_sort(stb->bot, length);
	while (i < length)
	{
		j = 0;
		while (j < length && stb->bot[j] != sta->bot[i])
			j++;
		sta->bot[i] = j;
		i++;
	}
	ft_memset(stb->bot, 0, MAX_SIZE * sizeof(int32_t));
	sta->length = length;
	sta->top = sta->bot + length - 1;
	stb->length = 0;
	stb->top = stb->bot;
	flip_order(sta->bot, sta->length);
}

size_t	ft_sort(t_stack *sta, t_stack *stb)
{
	t_med	median;
	uint8_t	lut[MAX_SIZE];
	size_t	lis_length;

	lis_length = ft_find_lis(sta, lut);
	while (sta->length > lis_length)
	{
		median = ft_get_median(sta->bot, sta->length, lut);
		ft_binary_push(sta, stb, median, lut);
	}
	while (stb->length > 0)
		ft_push_cheapest(sta, stb);
	finish_rotate(sta, stb);
	return (ft_command("000", sta, stb));
}

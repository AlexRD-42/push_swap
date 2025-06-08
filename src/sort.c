/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/08 14:39:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

// static void ft_print(t_stack *sta, t_stack *stb)
// {
// 	ft_putnbr(ft_command("000", sta, stb), 1);
// 	write(1, ", ", 2);
// 	ft_putnbr(ft_get_entropy(sta, stb), 1);
// 	write(1, "\n", 1);
// }

static void	finish_rotate(t_stack *sta, t_stack *stb)
{
	if (sta->bot[0] >= (int32_t) sta->length)
	{
		while (sta->bot[0] != 0)
			ft_command("ra", sta, stb);
	}
	else
	{
		while (sta->bot[0] != 0)
			ft_command("rra", sta, stb);
	}
}

size_t	ft_sort(t_stack *sta, t_stack *stb)
{
	t_med	median;
	uint8_t	lut[MAX_SIZE];
	int32_t	lis_out[MAX_SIZE];
	size_t	len_out;
	size_t	i;

	i = 0;
	ft_find_lis(sta->bot, sta->length, lis_out, &len_out);
	ft_memset(lut, 0, MAX_SIZE * sizeof(uint8_t));
	while (i < len_out)
		lut[lis_out[i++]] = 1;
	while (sta->length > len_out)
	{
		median = ft_get_median(sta->bot, sta->length, lut);
		ft_binary_push(sta, stb, median, lut);
	}
	while (stb->length > 0)
		ft_push_cheapest(sta, stb);
	finish_rotate(sta, stb);
	return (ft_command("000", sta, stb));
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
}

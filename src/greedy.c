/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:47:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/07 15:07:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

static void	rotate_and_push(t_stack *dst, t_stack *src, t_rots rots)
{
	while ((rots.src > 0 && rots.dst > 0))
	{
		ft_command("RR", dst, src);
		rots.src--;
		rots.dst--;
	}
	while ((rots.src < 0 && rots.dst < 0))
	{
		ft_command("RRR", dst, src);
		rots.src++;
		rots.dst++;
	}
	while (rots.dst > 0 && rots.dst-- > 0)
			ft_command("RA", dst, src);
	while (rots.src > 0 && rots.src-- > 0)
			ft_command("RB", dst, src);
	while (rots.dst++ < 0)
		ft_command("RRA", dst, src);
	while (rots.src++ < 0)
		ft_command("RRB", dst, src);
	ft_command("PA", dst, src);
}

static int64_t	moves_to_insert(int32_t *array, size_t length, int32_t value)
{
	size_t	i;
	int32_t	prev;
	int32_t	next;

	i = 0;
	while (i < length)
	{
		prev = array[(i + length - 1) % length];
		next = array[i];
		if ((value > prev && value < next) ||
			(prev > next && (value > prev || value < next)))
		{
			if (i <= length / 2)
				return ((int64_t) i);
			else
				return (-(int64_t)(length - i));
		}
		i++;
	}
	return (INT64_MAX);
}

static void	min_moves(t_rots *min, int64_t dst_rots, int64_t src_rots)
{
	int64_t	sum;

	if (dst_rots < 0 && src_rots < 0)
		sum = i64_abs(i64_min(dst_rots, src_rots));
	else if (dst_rots > 0 && src_rots > 0)
		sum = i64_abs(i64_max(dst_rots, src_rots));
	else
		sum = i64_abs(dst_rots) + i64_abs(src_rots);
	if (sum < min->sum)
	{
		min->dst = dst_rots;
		min->src = src_rots;
		min->sum = sum;
	}
}

// You need to find how many RA/RRAs and RB/RRBs each element will have
// To calculate the minimum moves, only rotations in the same direction can be double instructions
void	ft_push_cheapest(t_stack *sta, t_stack *stb)
{
	int64_t	i;
	int64_t	dst_rots;
	t_rots	min;

	min.sum = INT64_MAX;
	i = 0;
	while ((size_t) i <= stb->length / 2 && i < min.sum)
	{
		dst_rots = moves_to_insert(sta->bot, sta->length, stb->bot[i]);
		min_moves(&min, dst_rots, i + 1);
		dst_rots = moves_to_insert(sta->bot, sta->length, stb->bot[stb->length - 1 - i]);
		min_moves(&min, dst_rots, -i);
		i++;
	}
	rotate_and_push(sta, stb, min);
}

// void	ft_push_valid(t_stack *src, t_stack *dst, int32_t *filter, size_t lut_len)
// {
// 	size_t	i;
// 	int32_t	lut[1024];

// 	i = 0;
// 	ft_memset(lut, 0, 1024 * sizeof(int32_t));
// 	while (i < lut_len)
// 		lut[filter[i++]] = 1;
// 	while (src->length > lut_len)
// 	{
// 		if (lut[*src->top] == 0)
// 			ft_command("PB", src, dst);
// 		else
// 			ft_command("RRA", src, dst);
// 	}
// }
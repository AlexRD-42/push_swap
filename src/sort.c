/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/07 12:27:42 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "push_swap.h"

static void ft_print(t_stack *sta, t_stack *stb)
{
	ft_putnbr(ft_command("000", sta, stb), 1);
	write(1, ", ", 2);
	ft_putnbr(get_entropy(sta, stb), 1);
	write(1, "\n", 1);
}

void	ft_sort_mid(t_stack *sta, t_stack *stb, int32_t *array)
{
	t_median	median;
	size_t		count;
	size_t		length;
	size_t		i;

	i = 0;
	ft_print(sta, stb);
	while (sta->length > 3)
	{
		median = ft_get_median(array, 0, sta->length);
		ft_binary_push(sta, stb, median, 'B');
		ft_print(sta, stb);
	}
	ft_sort_three(sta, 3);
	i = 90 * stb->length / 100;
	while (stb->length > i)
		ft_push_single(sta, stb, array[i++]);
	ft_print(sta, stb);
	ft_command("XX", sta, stb);
}

t_median	ft_get_mean(int32_t *array, size_t length)
{
	t_median		med;
	const int32_t	min = i32_minrange(array, length);
	size_t			sum;
	size_t			i;

	i = 0;
	sum = 0;
	while (i < length)
		sum += array[i++];
	med.middle = sum / (length - (length != 0));
	med.lower = min + (med.middle - min) / 2;
	med.upper = med.middle + (med.middle - min) / 2;
	return (med);
}

// By counting the number of elements that binary push pushes, we can
// determine the range for the previous push
int32_t	ft_distance(t_stack *stack)
{
	int32_t	array[1024];
	int32_t	*ptr;
	int32_t	*end;
	size_t	i;

	ptr = array;
	end = array + stack->length - 1;
	*end-- = 1 + stack->length / 2;
	i = 1 + stack->length / 2;
	while (ptr <= end)
	{
		*ptr++ = ++i;
		if (ptr <= end)
			*end-- = i;
	}
	i = 0;
	while (i < stack->length)
	{
		array[i] *= (stack->length - stack->bot[i]) + stack->length;
		i++;
	}
	return(stack->bot[ft_get_min_index(array, stack->length)]);
}

void	ft_push_valid(t_stack *src, t_stack *dst, int32_t *filter, size_t lut_len)
{
	size_t	i;
	int32_t	lut[1024];

	i = 0;
	ft_memset(lut, 0, 1024 * sizeof(int32_t));
	while (i < lut_len)
		lut[filter[i++]] = 1;
	while (src->length != lut_len)
	{
		if (lut[*src->top] == 0)
			ft_command("PB", src, dst);
		else
			ft_command("RRA", src, dst);
	}
}

int64_t	moves_to_insert(int32_t *array, size_t length, int32_t value)
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

void	min_moves(t_rots *min, int64_t dst_rots, int64_t src_rots)
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

static void	ft_rotate_and_push(t_stack *dst, t_stack *src, t_rots rots)
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
	ft_rotate_and_push(sta, stb, min);
}

void	ft_finish_rotate(t_stack *sta, t_stack *stb)
{
	if (sta->bot[0] >= (int32_t) sta->length)
	{
		while (sta->bot[0] != 0)
			ft_command("RA", sta, stb);
	}
	else
	{
		while (sta->bot[0] != 0)
			ft_command("RRA", sta, stb);
	}
}

// Push A/B, Flip Logic, 0, 0, Rotate Back SRC, Rotate Back DST, Rotate SRC, Rotate DST
void	ft_sort_start(t_stack *sta, t_stack *stb, int32_t *array)
{
	t_median	median;
	int32_t		lis_out[1024];
	size_t		len_out;

	ft_print(sta, stb);
	ft_find_lis(sta->bot, sta->length, lis_out, &len_out);
	ft_push_valid(sta, stb, lis_out, len_out);
	while (stb->length > 0)
		ft_push_cheapest(sta, stb);
	ft_finish_rotate(sta, stb);
	ft_print(sta, stb);
}

void	ft_initialize(int32_t *array_a, int32_t *array_b, int32_t *array_s, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	ft_memcpy(array_s, array_a, length * sizeof(int32_t));
	ft_memset(array_b, 0, length * sizeof(int32_t));
	ft_insertion_sort(array_s, length);
	while (i < length)
	{
		j = 0;
		while (j < length && array_s[j] != array_a[i])
			j++;
		array_a[i] = j;
		i++;
	}
	i = 0;
	while (i < length)
	{
		array_s[i] = i;
		i++;
	}
}

#define LENGTH 500
int main()
{
	int32_t array_a[LENGTH];
	int32_t array_b[LENGTH];
	int32_t array_s[LENGTH];

	for (int i = 100; i < 100 + LENGTH; i++)
		array_a[i - 100] = i;
	ft_shuffle(array_a, LENGTH, time(NULL));
	ft_initialize(array_a, array_b, array_s, LENGTH);
	t_stack	stack_a = {array_a, array_a + LENGTH - 1, LENGTH};
	t_stack	stack_b = {array_b, array_b, 0};
	char	buffer[32];

	ft_sort_start(&stack_a, &stack_b, array_s);
	// fn_print_stacks(&stack_a, &stack_b);
	// while (1)
	// {
	// 	read(1, buffer, 32);
	// 	buffer[3] = 0;
	// 	ft_command(buffer, &stack_a, &stack_b);
	// 	fn_print_stacks(&stack_a, &stack_b);
	// }
}
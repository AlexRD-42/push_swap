/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/05 12:34:28 by adeimlin         ###   ########.fr       */
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

void    ft_find_lis2(int32_t *array, size_t length, int32_t *lis_out, size_t *out_len)
{
	int32_t	max_lis[1024];
	int32_t	prev[1024];
	size_t 	best_end = 0;
	size_t	best_len = 1;
	size_t	i;
	size_t	j;

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
	for (size_t idx = best_len; idx-- > 0; k = prev[k])
		lis_out[idx] = array[k];
	*out_len = best_len;
}

void	ft_find_lis(int32_t *array, size_t length)
{
	int32_t	lis_lengths[1024];
	int32_t	aux_array[1024];
	size_t	i;
	size_t	j;
	const size_t	length2 = length;

	i = 0;
	ft_memset(lis_lengths, 0, length * sizeof(size_t));
	while (++i < length)
	{
		j = 0;
		while (j < i)
		{
			if (array[i] > array[j++])
				lis_lengths[i]++;
		}
	}

	i = 0;
	while (length > 0)
	{
		length = ft_get_max_index(lis_lengths, length);
		j = 0;
		while (j < length2)
		{
			if (array[j] > array[length])
				lis_lengths[j] = 0;
			j++;
		}
		aux_array[i++] = array[length];
	}
}

void	ft_stalin_sort(t_stack *sta, t_stack *stb)
{
	int32_t	max_lis[1024];
	size_t	lis_len;
	size_t	i;

	i = 0;
	while (i++ < sta->length)
	{
		// ft_find_lis(sta->bot, sta->length);
		ft_find_lis(sta->bot, sta->length);
		// ft_find_lis2(sta->bot, sta->length, max_lis, &lis_len);
		ft_command("RAX", sta, stb);
	}
}

void	ft_sort_start(t_stack *sta, t_stack *stb, int32_t *array)
{
	t_median	median;
	size_t	i;

	ft_stalin_sort(sta, stb);
	// while (sta->length > 3)
	// 	ft_push_single(stb, sta, ft_distance(sta));
	// while (stb->length > 3)
	// 	ft_push_single(sta, stb, 1 / ft_distance(sta));
	// ft_print(sta, stb);
	// ft_binary_push(stb, sta, ft_get_mean(sta->bot, sta->length), 0b11000011);
	// while (sta->length > 3)
	// {
	// 	ft_binary_push(stb, sta, ft_get_mean(sta->bot, sta->length), 0b10000011);
	// }
	// ft_sort_three(sta, sta->length);
	// i = sta->length;
	// while (stb->length > sta->length)
	// 	ft_push_single(sta, stb, i++);
	// ft_print(sta, stb);
}
// Push A/B, Flip Logic, 0, 0, Rotate Back SRC, Rotate Back DST, Rotate SRC, Rotate DST
// void	ft_sort_start(t_stack *sta, t_stack *stb, int32_t *array)
// {
// 	t_median	median;

// 	ft_print(sta, stb);
// 	median = ft_get_median(array, 0, sta->length);
// 	ft_binary_push(stb, sta, median, 0b11000011);
// 	ft_print(sta, stb);
// 	median.lower = (median.middle + 75) / 2;
// 	median.middle = 74;
// 	ft_binary_push(sta, stb, median, 0b00000101);
// 	ft_print(sta, stb);
// 	while (sta->length > 3)
// 	{
// 		median = ft_get_median(array, 0, sta->length);
// 		ft_binary_push(stb, sta, median, 0b10000001);
// 		ft_print(sta, stb);
// 	}

// 	median = ft_get_median(array, i32_minrange(stb->bot, stb->length), 100);
// 	ft_binary_push(sta, stb, median, 3);
// 	ft_print(sta, stb);
// 	// ft_sort_mid(sta, stb, array);
// }

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/07 15:38:36 by adeimlin         ###   ########.fr       */
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

t_median	ft_get_mean(int32_t *array, size_t length, uint8_t *lut)
{
	t_median		med;
	int32_t			min;
	int32_t			max;
	size_t			i;

	i = 0;
	min = INT32_MAX;
	max = 0;
	while (i < length)
	{
		if (lut[array[i]] == 0 && array[i] < min)
			min = array[i];
		if (lut[array[i]] == 0 && array[i] > max)
			max = array[i];
		i++;
	}
	med.middle = min + (max - min) / 2;
	med.lower = min + (max - min) / 4;
	med.upper = max - (max - min) / 4;
	return (med);
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
	uint8_t		lut[1024];
	int32_t		lis_out[1024];
	size_t		len_out;
	size_t		i;

	i = 0;
	ft_find_lis(sta->bot, sta->length, lis_out, &len_out);
	ft_memset(lut, 0, 1024 * sizeof(uint8_t));
	while (i < len_out)
		lut[lis_out[i++]] = 1;
	while (sta->length > len_out)
	{
		median = ft_get_mean(sta->bot, sta->length, lut);
		ft_binary_push(stb, sta, median, lut);
	}
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
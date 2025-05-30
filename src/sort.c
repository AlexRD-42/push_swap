/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/30 11:10:52 by adeimlin         ###   ########.fr       */
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
}

void	ft_sort_mid(t_stack *sta, t_stack *stb, int32_t *array)
{
	t_median	median[16];
	t_median	med;
	size_t		count;
	size_t		length;
	size_t		i;

	i = 0;
	ft_print(sta, stb);
	median[i] = ft_get_median(array, 0, sta->length + stb->length);
	while (sta->length > 3)
	{
		median[++i] = ft_get_median(array, 0, sta->length);
		ft_binary_push(sta, stb, median[i], 'B');
		ft_print(sta, stb);
	}
	ft_print(sta, stb);
	ft_sort_three(sta, 3);
	i = sta->length;
	while (stb->length > 0)
		ft_push_single(sta, stb, array[i++]);
	ft_print(sta, stb);
	ft_command("XX", sta, stb);
}

void	ft_sort_start(t_stack *sta, t_stack *stb, int32_t *array)
{
	t_median	median;

	median = ft_get_median(array, 0, sta->length);
	while (median.count > 0)
	{
		if (*sta->top >= median.middle)
		{
			ft_command("PB", sta, stb);
			if (*stb->top >= median.upper)
				ft_command("RRB", sta, stb);
			median.count--;
		}
		else
			ft_command("RRA", sta, stb);
	}
	ft_sort_mid(sta, stb, array);
}

#define LENGTH 100
int main()
{
	int32_t array[LENGTH];
	int32_t array0[LENGTH];
	int32_t arrays[LENGTH];

	for (int i = 0; i < LENGTH; i++)
		array[i] = i;
	ft_shuffle(array, LENGTH, time(NULL));
	ft_memset(array0, 0, LENGTH * 4);
	t_stack	stack_a = {array, array + LENGTH - 1, LENGTH};
	t_stack	stack_b = {array0, array0, 0};
	char	buffer[32];

	ft_memcpy(arrays, array, LENGTH * 4);
	ft_insertion_sort(arrays, LENGTH);
	ft_sort_start(&stack_a, &stack_b, arrays);
	// fn_print_stacks(&stack_a, &stack_b);
	// while (1)
	// {
	// 	read(1, buffer, 32);
	// 	buffer[3] = 0;
	// 	ft_command(buffer, &stack_a, &stack_b);
	// 	fn_print_stacks(&stack_a, &stack_b);
	// }
}
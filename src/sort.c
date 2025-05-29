/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/29 19:30:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "push_swap.h"

void	ft_push_single(t_stack *sta, t_stack *stb, int32_t target)
{
	size_t	i;

	i = 0;
	while (stb->bot[i] != target && i < stb->length)
		i++;
	if (stb->bot[i] != target)
		return ;
	if (i >= stb->length / 2)
	{
		while (*stb->top != target)
			ft_command("RRB", sta, stb);
	}
	else
	{
		while (*stb->top != target)
			ft_command("RB", sta, stb);
	}
	ft_command("PA", sta, stb);
}

void	ft_sort_mid(t_stack *sta, t_stack *stb, int32_t *array)
{
	t_median	median[16];
	size_t		count;
	size_t		length;
	size_t		i;

	i = 0;
	median[i++] = ft_get_median(array, 0, sta->length + stb->length);
	while (sta->length > 0)
	{
		median[++i] = ft_get_median(array, 0, sta->length);
		ft_binary_push(sta, stb, median[i], 'B');
	}
	ft_sort_three(sta, stb, sta->length);
	count = ft_command("XX", sta, stb);
	array += sta->length;
	length = stb->length / 2 + stb->length / 4;
	while (stb->length > length)
		ft_push_single(sta, stb, *array++);

	// ----
	ft_putnbr(count, 1);
	write(1, ", ", 2);
	ft_putnbr(ft_command("XX", sta, stb), 1);
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

// Function to shuffle an array
void shuffle(int *array, int size)
{
	srand(time(NULL));

	for (int i = size - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

#define LENGTH 30
int main()
{
	int32_t array[LENGTH];
	int32_t array0[LENGTH];
	int32_t arrays[LENGTH];

	for (int i = 0; i < LENGTH; i++)
		array[i] = i;
	shuffle(array, LENGTH);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/03 17:34:47 by adeimlin         ###   ########.fr       */
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

// Challenges: Creating a median that 
void	ft_sort_start(t_stack *sta, t_stack *stb, int32_t *array)
{
	t_median	median;

	median = ft_get_median(array, 0, sta->length);
	ft_print(sta, stb);
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
	// ft_print(sta, stb);
	// while (median.middle != median.lower)
	// {
	// 	median = ft_get_median2(median.middle, 75);
	// 	ft_binary_push(sta, stb, median, 'A');
	// 	ft_print(sta, stb);
	// }
	// median.middle = 75;
	// while (median.middle != median.lower)
	// {
	// 	median = ft_get_median2(median.middle, 100);
	// 	ft_binary_push(sta, stb, median, 'A');		
	// }
	ft_sort_mid(sta, stb, array);
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
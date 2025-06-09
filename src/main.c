/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 20:06:22 by adeimlin         ###   ########.fr       */
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

	if (sta->length <= 5)
	{
		ft_sort_five(sta, stb);
		finish_rotate(sta, stb);
		return (ft_command("000", sta, stb));
	}
	lis_length = ft_find_lis(sta, lut);
	lis_length += lis_length == 1;
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

int	main(int argc, char **argv)
{
	int32_t	array_a[MAX_SIZE];
	int32_t	array_b[MAX_SIZE];
	t_stack	sta;
	t_stack	stb;

	if (argc <= 1 || argc >= MAX_SIZE)
		return (0);
	ft_memset(array_a, 0, MAX_SIZE * sizeof(int32_t));
	if (parse_input(argv, argc, array_a, (size_t) argc - 1))
		return (1);
	sta.bot = array_a;
	stb.bot = array_b;
	ft_initialize(&sta, &stb, argc - 1);
	if (is_sorted_asc(&sta, &stb))
		return (0);
	if (sta.length <= 2 && *sta.bot > *sta.top)
		ft_command("sa", &sta, &stb);
	else if (sta.length > 2)
		ft_sort(&sta, &stb);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// static void	ft_shuffle(int32_t *array, size_t size, int32_t seed)
// {
// 	int32_t	temp;
// 	size_t	j;

// 	srand(seed);
// 	while (size > 0)
// 	{
// 		size--;
// 		j = rand() % (size + 1);
// 		temp = array[size];
// 		array[size] = array[j];
// 		array[j] = temp;
// 	}
// }

// #define LENGTH 500
// #define NUM_RUNS 1000
// int main()
// {
// 	int32_t array_a[MAX_SIZE];
// 	int32_t array_b[MAX_SIZE];
// 	t_stack	sta;
// 	t_stack	stb;

// 	sta.bot = array_a;
// 	stb.bot = array_b;
// 	for (int j = 0; j < NUM_RUNS; j++)
// 	{
// 		srand(time(NULL) + rand() + j);
// 		for (int i = 0; i < LENGTH; i++)
// 			array_a[i] = i;
// 		ft_shuffle(sta.bot, LENGTH, time(NULL) + rand() + j);
// 		ft_initialize(&sta, &stb, LENGTH);
// 		size_t	sort_count = ft_sort(&sta, &stb);
// 		uint8_t	is_sort = is_sorted(&sta, &stb);
// 		// printf("%llu, %u\n", sort_count, is_sort);
// 		ft_command("CLR", &sta, &stb);
// 		if (is_sort == 0 || sort_count > 5000)
// 			is_sort = 1;
// 	}
// }
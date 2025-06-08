/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.s                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 10:56:25 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/08 12:22:54 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "push_swap.h"

// void	fn_print_stacks(const t_stack *a, const t_stack *b)
// {
// 	size_t	i;

// 	printf("Stack A (%zu):\t", a->length);
// 	i = 0;
// 	while (i < a->length)
// 	{
// 		printf("%d", a->bot[i]);
// 		i++;
// 		if (i != a->length)
// 			printf(", ", a->bot[i]);
// 	}
// 	printf("\nStack B (%zu):\t", b->length);
// 	i = 0;
// 	while (i < b->length)
// 	{
// 		printf("%d", b->bot[i]);
// 		i++;
// 		if (i != b->length)
// 			printf(", ", b->bot[i]);
// 	}
// 	printf("\n-------\n");	
// }

// #define SIZE 16
// int main()
// {
// 	int32_t array[SIZE] = {5, 2, 15, 7, 4, 13, 8, 10, 6, 14, 9, 3, 12, 11, 1, 16};
// 	int32_t array0[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// 	int32_t arrays[SIZE];
// 	t_median	median;
// 	t_stack	stack_a = {array, array + SIZE - 1, SIZE};
// 	t_stack	stack_b = {array0, array0, 0};
// 	char	buffer[32];

// 	ft_memcpy(arrays, array, SIZE * 4);
// 	median = ft_get_median(arrays, SIZE);
// 	fn_print_stacks(&stack_a, &stack_b);
// 	while (1)
// 	{
// 		read(1, buffer, 32);
// 		buffer[3] = 0;
// 		ft_command(buffer, &stack_a, &stack_b);
// 		fn_print_stacks(&stack_a, &stack_b);
// 	}
// }

static void	ft_shuffle(int32_t *array, size_t size, int32_t seed)
{
	int32_t	temp;
	size_t	j;

	srand(seed);
	while (size > 0)
	{
		size--;
		j = rand() % (size + 1);
		temp = array[size];
		array[size] = array[j];
		array[j] = temp;
	}
}

#define LENGTH 500
int main()
{
	int32_t array_a[1024];
	int32_t array_b[1024];
	t_stack	sta;
	t_stack	stb;

	sta.bot = array_a;
	stb.bot = array_b;
	for (int j = 0; j < 1; j++)
	{
		srand(time(NULL) + rand() + j);
		for (int i = 0; i < LENGTH; i++)
			array_a[i] = rand();
		ft_shuffle(sta.bot, LENGTH, time(NULL) + rand() + j);
		ft_initialize(&sta, &stb, LENGTH);
		ft_putnbr(ft_sort(&sta, &stb), 1);
		write(1, "\n", 1);
		ft_command("XXX", &sta, &stb);
	}
}
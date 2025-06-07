/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:41:11 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/07 14:51:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
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

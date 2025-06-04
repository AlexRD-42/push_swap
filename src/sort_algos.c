/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:48:58 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/03 12:02:44 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

void	ft_sort_three(t_stack *stack, size_t length)
{
	const uint8_t	boolean = (*stack->bot > *(stack->bot + 1)) + 
		(*(stack->bot + 1) > *stack->top) * 2 + (*stack->bot > *stack->top) * 4;

	if (length <= 2 && (*stack->bot > *stack->top))
		ft_command("SA", stack, NULL);
	else if (boolean == 1)
	{
		ft_command("RA", stack, NULL);
		ft_command("SA", stack, NULL);
	}
	else if (boolean == 2)
		ft_command("SA", stack, NULL);
	else if (boolean == 5)
		ft_command("RA", stack, NULL);
	else if (boolean == 6)
		ft_command("RRA", stack, NULL);
	else if (boolean == 7)
	{
		ft_command("RRA", stack, NULL);
		ft_command("SA", stack, NULL);
	}
}

// Finds the shortest path to push a target element
// Default assumption is dst = A, src = B
void	ft_push_single(t_stack *dst, t_stack *src, int32_t target)
{
	size_t	i;

	i = 0;
	while (src->bot[i] != target && i < src->length)
		i++;
	if (src->bot[i] != target)
		return ;
	if (i >= src->length / 2)
	{
		while (*src->top != target)
			ft_command("RRB", dst, src);
	}
	else
	{
		while (*src->top != target)
			ft_command("RB", dst, src);
	}
	ft_command("PA", dst, src);
}

// Push Range, assigns weights for N elements and chooses the best weight
// N Elements are increased if chain is unbroken
// It will look at three elements: Bottom, Top, Top - 1
// Or Bottom, Bottom - 1, Top, Top -1, Top - 2
// uint8_t	ft_push_range(t_stack *dst, t_stack *src)
// {
// 	size_t	i;
// 	size_t	circ_index;
// 	const int32_t	weight[5] = {6, 3, 0, 3, 6};
// 	int32_t	min;

// 	if (src->length <= 5)
// 	{
// 		ft_push_single(dst, src, i32_minrange(src->bot, src->length)); 
// 		return ;
// 	}
// 	i = src->length - 3;
// 	min = src->bot[i % src->length];
// 	while (i < 5)
// 	{
// 		if (src->bot[i % src->length] + weight[i % src->length] < min)
// 			min = src->bot[i % src->length];
// 	}
// 	ft_push_single(dst, src, min);
// }

uint8_t	ft_push_range_max(t_stack *dst, t_stack *src)
{
	size_t	i;
	size_t	j;
	size_t	circ_index;
	const int32_t	weight[5] = {6, 3, 0, 3, 6};
	int32_t	max;

	i = src->length - 3;
	j = 0;
	max = i % src->length;
	while (j < 5)
	{
		circ_index = i % src->length;
		if (src->bot[circ_index] - weight[j] > src->bot[max])
			max = circ_index;
		i++;
		j++;
	}
	ft_push_single(dst, src, src->bot[max]);
}
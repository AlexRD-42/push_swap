/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:48:58 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/30 12:29:40 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

void	ft_sort_three(t_stack *stack, size_t length)
{
	const uint8_t	boolean = (*stack->bot > *(stack->bot + 1)) + 
		(*(stack->bot + 1) > *stack->top) * 2 + (*stack->bot > *stack->top) * 4;

	if (length <= 2)
	{
		if (*stack->bot > *stack->top)
			ft_command("SA", stack, NULL);
		return ;
	}
	if (boolean == 2)
		ft_command("SA", stack, NULL);
	else if (boolean == 1)
	{
		ft_command("RA", stack, NULL);
		ft_command("SA", stack, NULL);
	}
	else if (boolean == 6)
		ft_command("RRA", stack, NULL);
	else if (boolean == 5)
		ft_command("RA", stack, NULL);
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
uint8_t	ft_push_range(t_stack *dst, t_stack *src, int32_t target, uint8_t chain)
{
	int32_t	array[5];

	if (src->length < 5)

}

// // Finds the shortest path to push a target element, (0 for PA)
// void	ft_push_single(t_stack *dst, t_stack *src, int32_t target, uint8_t mode)
// {
// 	size_t					i;
// 	static const char	cmd[2][3][4] = 
// 		{{"RRB", "RB", "PA"}, {"RRA", "RA", "PB"}};

// 	i = 0;
// 	while (src->bot[i] != target && i < src->length)
// 		i++;
// 	if (src->bot[i] != target)
// 		return ;
// 	if (i >= src->length / 2)
// 	{
// 		while (*src->top != target)
// 			ft_command(cmd[mode != 0][0], dst, src);
// 	}
// 	else
// 	{
// 		while (*src->top != target)
// 			ft_command(cmd[mode != 0][1], dst, src);
// 	}
// 	ft_command(cmd[mode != 0][2], dst, src);
// }
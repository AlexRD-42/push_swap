/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/20 12:55:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

void	ft_selection_sort(int32_t *array, size_t length)
{
	int32_t			temp;
	int32_t			*min;
	int32_t			*ptr;
	const int32_t	*end = array + length;

	while (array < end - 1)
	{
		min = array;
		ptr = array + 1;
		while (ptr < end)
		{
			if (*ptr < *min)
				min = ptr;
			ptr++;
		}
		temp = *array;
		*array = *min;
		*min = temp;
		array++;
	}
}

t_stats	ft_get_stats(int32_t *array, size_t length)
{
	t_stats	stats;

	ft_selection_sort(array, length);
	stats.min = *array;
	stats.med = *(array + (length - 1) / 2);
	stats.max = *array;
	return (stats);
}

size_t	ft_sort_status(t_stack *sta, t_stack *stb)
{
	size_t	i;

	i = 1;
	while (i < sta->length)
	{
		if (sta->bot[i - 1] > sta->bot[i])
			return (sta->length - i - 1);
		i++;
	}
	i = 1;
	while (i < stb->length)
	{
		if (stb->bot[i - 1] < stb->bot[i])
			return (stb->length - i - 1);
		i++;
	}
	return (0);
}
// Could add double instructions as soon as B.length > 2
// Would require only a check to see if length is bigger than the other
// Sort both arrays while they are 
void	ft_push_start(t_stack *sta, t_stack *stb, t_stats stats)
{
	while (stb->length < sta->length - 1)
	{
		if (*sta->top > stats.med)
			ft_command("PB", sta, stb);
		else
		{
			if (ft_delta_sum(sta->bot, sta->length) < 0)
				while (*sta->top < stats.med)
					ft_command("RA", sta, stb);
			else
				while (*sta->top < stats.med)
					ft_command("RRA", sta, stb);
		}
	}
}

void	ft_get_delta(t_stack *sta, t_stack *stb)
{
	
}

// How to rank decisions? 
void	ft_sort(t_stack *sta, t_stack *stb, t_stats stats)
{
	if (*sta->top > *sta->bot && *stb->top < *stb->bot)
		ft_command("RR", &sta, &stb);
}

int main()
{
	int32_t array[8] = {5, 2, 7, 3, 4, 1, 8, 6};
	int32_t array0[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int32_t arrays[8];
	t_stats	stats;
	t_stack	stack_a = {array, array + 7, 8};
	t_stack	stack_b = {array0, array0, 0};

	ft_memcpy(arrays, array, 8*4);
	stats = ft_get_stats(arrays, 8);
	ft_push_start(&stack_a, &stack_b, stats);
}
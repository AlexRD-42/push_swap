/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:35:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/23 13:04:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

// Could add double instructions as soon as B.length > 2
// Would require only a check to see if length is bigger than the other
// Sort both arrays while they are 

// Pushes should always be done when valid
// Swaps should be done if top belongs in h2
	// Or if both numbers belong in h1 AND top - 1 > top

// Rotates should be done if the bottom belongs in top
// R. Rotates should be done if top belongs in bottom

void	ft_push_start(t_stack *sta, t_stack *stb, t_median median)
{
	const size_t	length = stb->length - (stb->length & 1);

	while (stb->length < length)
	{
		if (*sta->top > median.mid)
			ft_command("PB", sta, stb);
		else
		{
			if (ft_delta_count(sta->bot, sta->length) < 0)
				while (*sta->top < median.mid)
					ft_command("RA", sta, stb);
			else
				while (*sta->top < median.mid)
					ft_command("RRA", sta, stb);
		}
	}
}

// void	ft_sort(t_stack *sta, t_stack *stb, t_stats stats)
// {
// 	if (*sta->top > *sta->bot && *stb->top < *stb->bot)
// 		ft_command("RR", &sta, &stb);
// }

int main()
{
	int32_t array[8] = {5, 2, 7, 3, 4, 1, 8, 6};
	int32_t array0[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int32_t arrays[8];
	t_median	median;
	t_stack	stack_a = {array, array + 7, 8};
	t_stack	stack_b = {array0, array0, 0};

	ft_memcpy(arrays, array, 8*4);
	median = ft_get_median(arrays, 8);
	ft_push_start(&stack_a, &stack_b, median);
}

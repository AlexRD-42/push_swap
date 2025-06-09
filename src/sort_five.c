/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:10:32 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/09 19:40:58 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

static
size_t	ft_get_min_index(int32_t *array, size_t length)
{
	size_t	i;
	size_t	min;

	min = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] < array[min])
			min = i;
		i++;
	}
	return (min);
}

static
void	ft_sort_three(t_stack *sta, t_stack *stb)
{
	const size_t	min_index = ft_get_min_index(sta->bot, sta->length);

	if (min_index == 1)
		ft_command("rra", sta, stb);
	else if (min_index == 2)
		ft_command("ra", sta, stb);
	if (sta->bot[1] > sta->bot[2])
		ft_command("sa", sta, stb);
}

void	ft_sort_five(t_stack *sta, t_stack *stb)
{
	while (sta->length > 3)
		ft_command("pb", sta, stb);
	if (*stb->bot < *stb->top)
		ft_command("sb", sta, stb);
	ft_sort_three(sta, stb);
	while (stb->length > 0)
		ft_push_cheapest(sta, stb);
}

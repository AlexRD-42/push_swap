/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:07:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/08 16:06:45 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"

static uint8_t	push_is_valid(t_stack *stack, t_med med, uint8_t *lut)
{
	size_t	i;

	i = 0;
	while (i < stack->length)
	{
		if (stack->bot[i] >= med.middle && !lut[stack->bot[i]])
			return (1);
		i++;
	}
	return (0);
}

void	ft_binary_push(t_stack *sta, t_stack *stb, t_med med, uint8_t *lut)
{
	const uint8_t	mode = (stb->length == 0);

	while (push_is_valid(sta, med, lut))
	{
		if (*sta->top >= med.middle && !lut[*sta->top])
		{
			ft_command("pb", sta, stb);
			if ((mode && *stb->top <= med.upper) || (!mode && *stb->top >= med.upper))
				ft_command("rb", sta, stb);
		}
		else
			ft_command("ra", sta, stb);
	}
}

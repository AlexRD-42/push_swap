/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:07:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/07 15:06:27 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"

static t_thr	ft_get_thr(int32_t value, t_median med, uint8_t mode)
{
	t_thr	thr;

	if (mode == 0)
	{
		thr.src = value >= med.middle;
		thr.dst = value <= med.upper;
	}
	else
	{
		thr.src = value >= med.middle;
		thr.dst = value >= med.upper;
	}
	return (thr);
}

static uint8_t	push_is_valid(t_stack *src, t_median med, uint8_t *lut)
{
	size_t	i;

	i = 0;
	while (i < src->length)
	{
		if (src->bot[i] >= med.middle && !lut[src->bot[i]])
			return (1);
		i++;
	}
	return (0);
}

void	ft_binary_push(t_stack *dst, t_stack *src, t_median med, uint8_t *lut)
{
	t_thr	thr;
	uint8_t	mode;

	mode = dst->length == 0;
	while (push_is_valid(src, med, lut))
	{
		thr = ft_get_thr(*src->top, med, mode);
		if (thr.src && !lut[*src->top])
		{
			ft_command("PA", dst, src);
			if (thr.dst)
				ft_command("RRA", dst, src);
		}
		else
			ft_command("RRB", dst, src);
	}
}

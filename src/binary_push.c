/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:07:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/05 09:35:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"

// 1 fix DST, 2 fix SRC, 3 fix BOTH
static void	ft_rotate_back(t_stack *dst, t_stack *src, t_rots rots, uint8_t mode)
{
	while (mode == 3 && rots.src && rots.dst)
	{
		ft_command("RR", dst, src);
		rots.src--;
		rots.dst--;
	}
	while ((mode == 1 || mode == 3) && rots.dst-- > 0)
		ft_command("RA", dst, src);
	while ((mode == 2 || mode == 3) && rots.src-- > 0)
		ft_command("RB", dst, src);
}

static t_thr	ft_get_thr(int32_t value, t_median med, uint8_t mode)
{
	t_thr	thr;

	if (mode == 0)
	{
		thr.src = value <= med.middle;
		thr.dst = value >= med.lower;
	}
	if (mode == 1)
	{
		thr.src = value <= med.middle;
		thr.dst = value <= med.lower;
	}
	else if (mode == 2)
	{
		thr.src = value >= med.middle;
		thr.dst = value <= med.upper;
	}
	else if (mode == 3)
	{
		thr.src = value >= med.middle;
		thr.dst = value >= med.upper;
	}
	return (thr);
}

static uint8_t	ft_push_is_valid(t_stack *src, t_median med, uint8_t mode)
{
	size_t	i;

	i = 0;
	if (mode)
	{
		while (i < src->length)
		{
			if (src->bot[i] >= med.middle)
				return (1);
			i++;
		}
	}
	else
	{
		while (i < src->length)
		{
			if (src->bot[i] <= med.middle)
				return (1);
			i++;
		}
	}
	return (0);
}

// Default is dst = A , src = B
// Push A/B, Flip Logic, 0, 0, Rotate Back SRC, Rotate Back DST, Rotate SRC, Rotate DST
size_t	ft_binary_push(t_stack *dst, t_stack *src, t_median med, uint8_t mode)
{
	size_t	num_pushes;
	t_thr	thr;
	t_rots	rots;

	rots.dst = 0;
	rots.src = 0;
	num_pushes = 0;
	mode += 64 * (dst->length == 0 && !(mode & 64));
	while (ft_push_is_valid(src, med, mode & 128))
	{
		thr = ft_get_thr(*src->top, med, mode >> 6);
		if (thr.src)
		{
			num_pushes += ft_command("PA", dst, src);
			if (thr.dst && (mode & 1))
			{
				ft_command("RRA", dst, src);
				rots.dst++;
			}
		}
		else if (mode & 2)
		{
			ft_command("RRB", dst, src);
			rots.src++;
		}
	}
	ft_rotate_back(dst, src, rots, (mode & 12) >> 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:07:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/04 10:02:48 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include "push_swap.h"

static void	ft_rotate_back(t_stack *dst, t_stack *src, size_t dst_rot, size_t src_rot)
{
	while (src_rot && dst_rot)
	{
		ft_command("RR", dst, src);
		src_rot--;
		dst_rot--;
	}
	while (src_rot-- > 0)
		ft_command("RB", dst, src);
	while (dst_rot-- > 0)
		ft_command("RA", dst, src);
}

static void	ft_binary_push_b(t_stack *sta, t_stack *stb, t_median med)
{
	size_t	num_rotates;

	num_rotates = 0;
	while (med.count > 0)
	{
		if (*sta->top >= med.middle)
		{
			ft_command("PB", sta, stb);
			if (*stb->top <= med.upper)
			{
				ft_command("RRB", sta, stb);
				num_rotates++;
			}
			med.count--;
		}
		else
			ft_command("RRA", sta, stb);
	}
	while (num_rotates > 0)
	{
		ft_command("RB", sta, stb);
		num_rotates--;
	}
}



// One push where
static void	ft_binary_push_a(t_stack *sta, t_stack *stb, t_median med)
{
	size_t	dst_nrot;
	size_t	src_nrot;

	dst_nrot = 0;
	src_nrot = 0;
	while (med.count > 0)
	{
		if (*stb->top <= med.middle)
		{
			ft_command("PA", sta, stb);
			if (*sta->top >= med.lower)
			{
				ft_command("RRA", sta, stb);
				dst_nrot++;
			}
			med.count--;
		}
		else
		{
			ft_command("RRB", sta, stb);
			src_nrot++;
		}
	}
	ft_rotate_back(sta, stb, dst_nrot, src_nrot);
}



void	ft_binary_push(t_stack *sta, t_stack *stb, t_median med, uint8_t mode)
{
	if (mode == 'A')
		ft_binary_push_a(sta, stb, med);
	else
		ft_binary_push_b(sta, stb, med);
}

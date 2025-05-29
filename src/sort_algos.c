/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:48:58 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/29 18:50:24 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

void	ft_sort_three(t_stack *sta, t_stack *stb, size_t length)
{
	const uint8_t	boolean = (*sta->bot > *(sta->bot + 1)) + 
		(*(sta->bot + 1) > *sta->top) * 2 + (*sta->bot > *sta->top) * 4;

	if (length <= 2)
	{
		if (*sta->bot > *sta->top)
			ft_command("SA", sta, stb);
		return ;
	}
	if (boolean == 2)
		ft_command("SA", sta, stb);
	else if (boolean == 1)
	{
		ft_command("RA", sta, stb);
		ft_command("SA", sta, stb);
	}
	else if (boolean == 6)
		ft_command("RRA", sta, stb);
	else if (boolean == 5)
		ft_command("RA", sta, stb);
	else if (boolean == 7)
	{
		ft_command("RRA", sta, stb);
		ft_command("SA", sta, stb);
	}		
}


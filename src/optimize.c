/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:53:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/30 10:05:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdint.h>
#include <stddef.h>
#include "push_swap.h"

// Count rotations instead of next match only, the only factor that matters for rotations is Push

// Find: PA then PB, RRA then RA, 
// static void	ft_match_pattern(uint8_t cmd1[3], uint8_t cmd2[3])
// {
	
// }

void	ft_optimize(uint8_t cmd[1024][3], size_t index)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (i < index)
	{
		len = 1 + (cmd[i - 1][2] != 0);
		if ((cmd[i - 1][len] ^ cmd[i][len]) == ('A' ^ 'B')) // This catches PB PA
		{
			ft_memcpy(cmd[i], "XXX", 3);
			ft_memcpy(cmd[j++], cmd[i++ - 1], 3);
			cmd[j - 1][len] = cmd[j - 1][0];
		}
		else
			ft_memcpy(cmd[j++], cmd[i - 1], 3);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/15 12:09:37 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

typedef struct s_stack
{
	int32_t	*array;
	size_t	length;
}	t_stack;

typedef enum e_function_index
{
	CMD_SA,
	CMD_SB,
	CMD_SS,
	CMD_PA,
	CMD_PB,
	CMD_RA,
	CMD_RB,
	CMD_RR,
	CMD_RRA,
	CMD_RRB,
	CMD_RRR
}	t_fnindex;

// See if it's better to define prototypes within files
int64_t	ft_atoi(const char *num_str);
void	ft_putnbr(int64_t n, int fd);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);
void	ft_command(t_fnindex fn_index, t_stack *a, t_stack *b);

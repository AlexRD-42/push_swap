/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:12:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/19 15:00:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

typedef struct s_stats
{
	int32_t	max;
	int32_t	min;
	float	avg;
	float	mad;
}	t_stats;

typedef union u_32
{
	int32_t		i;
	uint32_t	u;
	float		f;
	uint8_t		b[4];
}	t_32;

typedef union u_64
{
	int32_t		i32[2];
	uint32_t	u32[2];
	int64_t		i64;
	uint64_t	u64;
	float		f32[2];
	double		f64;
	uint8_t		b[8];
}	t_64;


t_stats	ft_get_stats(int32_t *array, size_t length)
{
	t_stats	stats;
	t_64	sum;
	size_t	i;

	i = 1;
	sum.i64 = *array;
	stats.max = *array;
	stats.min = *array;
	while (i < length)
	{
		asm("cmp %2, %0\n\t" "cmovl %2, %0\n\t" "cmp %1, %2\n\t" "cmovl %2, %1"
			: "+r"(stats.max), "+r"(stats.min) : "r"(array[i]));
		sum.i64 += array[i++];
	}
	stats.avg = (float)((double) sum.i64 / (double) i);
	i = 0;
	stats.mad = 0;
	while (i < length)
	{
		sum.f32[0] = ((float)array[i++] - stats.avg);
		sum.i32[0] &= 0x7FFFFFFF;
		stats.mad += sum.f32[0];
	}
	stats.mad = stats.mad / length;
	return (stats);
}

int main()
{
	int32_t array[10] = {1,0,0,4,5,6,7,8,9,10};

	ft_get_stats(array, 10);
}
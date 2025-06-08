#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "push_swap.h"

static
void	ft_shuffle(int32_t *array, size_t size, int32_t seed)
{
	int32_t	temp;
	size_t	j;

	srand(seed);
	while (size > 0)
	{
		size--;
		j = rand() % (size + 1);
		temp = array[size];
		array[size] = array[j];
		array[j] = temp;
	}
}

#define LENGTH 500
int main()
{
	int32_t	array_a[MAX_SIZE];
	int32_t	array_b[MAX_SIZE];
	t_stack	sta;
	t_stack	stb;

	ft_memset(array_a, 0, MAX_SIZE * sizeof(int32_t));
	for (int i = 0; i < LENGTH; i++)
		array_a[i] = i;
	ft_shuffle(array_a, LENGTH, time(NULL));
	sta.bot = array_a;
	stb.bot = array_b;
	ft_initialize(&sta, &stb, LENGTH);
	ft_sort(&sta, &stb);
	ft_putnbr(ft_command("000", &sta, &stb), 1);
}
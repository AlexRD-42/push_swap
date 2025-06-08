// By counting the number of elements that binary push pushes, we can
// determine the range for the previous push
int32_t	ft_distance(t_stack *stack)
{
	int32_t	array[1024];
	int32_t	*ptr;
	int32_t	*end;
	size_t	i;

	ptr = array;
	end = array + stack->length - 1;
	*end-- = 1 + stack->length / 2;
	i = 1 + stack->length / 2;
	while (ptr <= end)
	{
		*ptr++ = ++i;
		if (ptr <= end)
			*end-- = i;
	}
	i = 0;
	while (i < stack->length)
	{
		array[i] *= (stack->length - stack->bot[i]) + stack->length;
		i++;
	}
	return(stack->bot[ft_get_min_index(array, stack->length)]);
}

size_t	ft_get_entropy(t_stack *sta, t_stack *stb)
{
	size_t	i;
	size_t	j;
	size_t	total_entropy;

	i = 0;
	j = 0;
	total_entropy = 0;
	while (i < sta->length)
	{
		total_entropy += i64_absdiff(i, sta->bot[i]);
		i++;
	}
	j = stb->length;
	while (j > 0)
	{
		total_entropy += i64_absdiff(i, stb->bot[j - 1]);
		j--;
		i++;
	}
	return (total_entropy);
}

t_median	ft_get_median(int32_t *array, size_t start, size_t end)
{
	t_median	median;
	size_t		length;

	length = end - start;
	median.count = length / 2 + (length % 2 != 0);
	length -= (end != start);
	array += start;
	median.lower = *(array + length / 4);
	median.middle = *(array + length / 2 + (length % 2 != 0));
	median.upper = *(array + length - length / 4);
	return (median);
}

t_median	ft_get_median2(size_t start, size_t end)
{
	t_median	median;
	size_t		length;

	length = end - start;
	median.count = length / 2;
	median.lower = start + length / 4;
	median.middle = start + length / 2;
	median.upper = end - length / 4;
	return (median);
}

int64_t	ft_delta_sum(int32_t *array, size_t length)
{
	size_t	i;
	int64_t	sum;

	sum = 0;
	i = 0;
	while (i < length / 2)
	{
		sum += array[i];
		i++;
	}
	i += (length & 1);
	while (i < length)
	{
		sum -= array[i];
		i++;
	}
	return (sum);
}

// Need to implement a is_circular_sorted
int64_t	ft_delta_count(int32_t *array, size_t length)
{
	size_t	i;
	int64_t	count;

	count = 0;
	i = 1;
	while (i < length / 2)
	{
		count += array[i - 1] > array[i];
		i++;
	}
	i += (length & 1);
	while (i < length)
	{
		count -= array[i - 1] > array[i];
		i++;
	}
	return (count);
}

uint8_t	ft_sort_status(t_stack *sta, t_stack *stb)
{
	uint8_t	status;
	size_t	i;

	i = 1;
	status = 0;
	while (i < sta->length)
	{
		if (sta->bot[i - 1] > sta->bot[i])
		{
			status += 1;
			break ;
		}
		i++;
	}
	i = 1;
	while (i < stb->length)
	{
		if (stb->bot[i - 1] < stb->bot[i])
		{
			status += 2;
			break ;
		}
		i++;
	}
	return (status);
}

void	ft_push_valid(t_stack *src, t_stack *dst, int32_t *filter, size_t lut_len)
{
	size_t	i;
	int32_t	lut[1024];

	i = 0;
	ft_memset(lut, 0, 1024 * sizeof(int32_t));
	while (i < lut_len)
		lut[filter[i++]] = 1;
	while (src->length > lut_len)
	{
		if (lut[*src->top] == 0)
			ft_command("PB", src, dst);
		else
			ft_command("RRA", src, dst);
	}
}

void    ft_find_lis2(int32_t *array, size_t length, int32_t *lis_out, size_t *len_out)
{
	size_t	i;
	size_t	j;
	int32_t	max_lis[1024];
	int32_t	prev[1024];
	size_t 	best_end = 0;
	size_t	best_len = 1;

	for (i = 0; i < length; ++i)
	{
		max_lis[i] = 1;
		prev[i] = -1;
		for (j = 0; j < i; ++j)
			if (array[j] > array[i] && max_lis[j] + 1 > max_lis[i])
			{
				max_lis[i] = max_lis[j] + 1;
				prev[i] = j;
			}
		if ((size_t)max_lis[i] > best_len)
		{
			best_len = max_lis[i];
			best_end = i;
		}
	}
	size_t k = best_end;
	for (i = best_len; i-- > 0; k = prev[k])
		lis_out[i] = array[k];
	*len_out = best_len;
}

int64_t	mov_mean(int64_t *array, size_t length)
{
	size_t	i;
	size_t	j;
	uint8_t	mod;
	int64_t	sum;
	int64_t	mean;

	sum = array[0];
	mean = array[0];
	mod = 0;
	i = 1;
	while (i < length)
	{
		mod++;
		j = i64_min(1LL << mod, length);
		while (i < j)
			sum += array[i++];
		if (i != length)
			mean = sum >> mod;
		else
			mean = sum / (i - 1);
	}
	return (mean);
}

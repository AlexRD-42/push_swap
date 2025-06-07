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


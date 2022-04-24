/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:18:56 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/24 16:56:06 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "darray.h"

t_darray	*new_darray_malloc(size_t init_capacity)
{
	t_darray	*arr;

	arr = malloc(sizeof(*arr));
	if (arr != NULL)
	{
		arr->size = 0;
		arr->capacity = init_capacity;
		arr->data = new_data_malloc(init_capacity);
		if (arr->data == NULL)
		{
			free(arr);
			arr = NULL;
		}
	}
	return (arr);
}

void	clear_darray(t_darray *arr)
{
	size_t	idx;

	idx = 0;
	while (idx < arr->size)
	{
		darray_set_data(arr, idx, NULL);
		++idx;
	}
	arr->size = 0;
}

void	*new_data_malloc(size_t init_capacity)
{
	void	*data;

	data = malloc(init_capacity * sizeof(size_t));
	return (data);
}

void	darray_set_data(t_darray *arr, size_t index, void *data)
{
	if (arr->data[index] != NULL)
		free(arr->data[index]);
	arr->data[index] = data;
}

bool	darray_is_empty(t_darray *arr)
{
	size_t	i;

	i = 0;
	while (i < arr->size)
	{
		if (arr->data[i] != NULL)
			return (false);
		++i;
	}
	return (true);
}

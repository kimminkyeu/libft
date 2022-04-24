/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:24:41 by minkyeki          #+#    #+#             */
/*   Updated: 2022/04/24 17:10:41 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DARRAY_H
# define DARRAY_H

# include <stddef.h>
# include <stdbool.h>

/* ---------------------------
 * * Type define for D-array (Works as same as Linked list in Libft. */
typedef struct s_darray {
	size_t		size;
	size_t		capacity;
	void		**data;
}	t_darray;

extern void		*new_data_malloc(size_t init_capacity);
extern void		darray_set_data(t_darray *arr, size_t index, void *data);
extern t_darray	*new_darray_malloc(size_t init_capacity);
extern void		clear_darray(t_darray *vec);
extern bool		darray_is_empty(t_darray *vec);
extern void		*darray_reserve(t_darray *vec, size_t new_capacity);
extern void		darray_push_back(t_darray *vec, void *data);
extern void		darray_pop_back(t_darray *vec);
extern void		*darray_shrink_to_fit(t_darray *vec);
extern void		darray_iterate(t_darray *arr, void (*f)(void *));
extern t_darray	*darray_map_malloc(t_darray *arr, void *(*f)(void *));

#endif /* DARRAY_H */

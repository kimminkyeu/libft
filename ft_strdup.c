/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:28:13 by minkyeki          #+#    #+#             */
/*   Updated: 2022/03/22 15:59:45 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

extern size_t	ft_strlen(const char *str);
extern void		*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tmp;

	size = ft_strlen(s1);
	tmp = ft_calloc((size + 1), sizeof(*tmp));
	if (!tmp)
		return (NULL);
	while (size > 0)
	{
		tmp[size] = s1[size];
		--size;
	}
	tmp[0] = s1[0];
	return (tmp);
}

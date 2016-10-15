/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:57:25 by pmartine          #+#    #+#             */
/*   Updated: 2016/10/15 16:11:49 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/rtv1.h"

t_vec	*new_vec(double x,double y, double z)
{
	t_vec	*vec;

	if (!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;

	return(vec);
}

t_vec	*ft_vector(int fd)
{
	double x;
	double y;
	double z;
	char	*line;

	if (get_next_line(fd, &line) < 1)
		exit(-1);
	x = ft_atodouble(&line);
	y = ft_atodouble(&line);
	z = ft_atodouble(&line);
	return (new_vec(x, y, z));
}

void	ft_deleted_vect(t_vec *vect)
{
	free(vect);
}

t_vec	add_vect(t_vec	*v1, t_vec	*v2)
{
	t_vec	v3;

	v3.x = v1->x + v2->x;
	v3.y = v1->y + v2->y;
	v3.z = v1->z + v2->z;
	return (v3);
}

t_vec	sub_vect(t_vec *v1, t_vec *v2)
{
	t_vec	v3;

	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	return (v3);
}

t_vec	mult_vect(t_vec	*v1, double fact)
{
	t_vec	v2;
	v2.x = v1->x * fact;
	v2.y = v1->y * fact;
	v2.z = v1->z * fact;
	return (v2);
}

double	scale(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec	norm_vect(t_vec *v1)
{
	t_vec	v2;
	double	len;

	len = sqrtf((v1->x * v1->x) + (v1->y * v1->y) + (v1->z * v1->z));
	v2.x = v1->x / len;
	v2.y = v1->y / len;
	v2.z = v1->z / len;
	return (v2);
}

t_vec	cross_vec(t_vec v1, t_vec v2)
{
	t_vec		result;

	result.x = v1.y * v2.z - v2.y - v1.z;
	result.y = v1.z * v2.x - v2.z * v1.x;
	result.z = v1.x * v2.y - v2.x * v1.y;
	return (result);
}
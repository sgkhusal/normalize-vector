/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:51:08 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/09 11:34:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normalize.h"

int	main(int argc, char **argv)
{
	t_vector	vector;
	t_vector	normalized;

	if (argc != 4)
	{
		printf("Usage: ./normalize x y z\n");
		return (1);
	}
	if (!is_valid_input(&argv[1]))
	{
		printf("Invalid argument. Accept only numbers\n");
		return (1);
	}
	vector = set_vector(ft_atod(argv[1]), ft_atod(argv[2]), ft_atod(argv[3]));
	normalized = normalize_vector(vector);
	printf("normalized vector: [%f,%f,%f]\n", normalized.x, normalized.y,
		normalized.z);
	return (0);
}

double	vector_length(t_vector vector)
{
	double	length;

	length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	return (length);
}

t_vector	normalize_vector(t_vector vector)
{
	double	length;
	double	x;
	double	y;
	double	z;

	length = vector_length(vector);
	x = vector.x / length;
	y = vector.y / length;
	z = vector.z / length;
	return (set_vector(x, y, z));
}

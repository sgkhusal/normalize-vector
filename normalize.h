/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:14:32 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/09 11:38:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMALIZE_H
# define NORMALIZE_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vector;

t_vector	normalize_vector(t_vector vector);
t_vector	set_vector(double x, double y, double z);
double		vector_length(t_vector vector);

/* utils */
bool		is_valid_input(char *input[]);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
double		ft_atod(char *nb);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif

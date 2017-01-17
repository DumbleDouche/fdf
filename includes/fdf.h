/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 07:06:37 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/17 00:27:54 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
// #include "../mlx/mlx.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef FDF_H
#define FDF_H

#define	ERROR  "Something went wrong"
#define BADARG "usage: ./fdf file"
#define PROPER "./fdf ended properly"

typedef struct		s_size
{
	size_t			x;
	size_t			y;
}					t_size;

typedef struct		s_point
{
	size_t			x;
	size_t			y;
	long			z;
	struct s_point	*next;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_size			size;
}					t_env;

int					draw(t_env e, t_size size);
int					print_key(int keycode, void *e);
int					print_lst(t_point *node);
void				ft_exit(char *error);
void				lst_append(t_point **node, size_t x, size_t y, long z);
t_env				setup(char *name);
t_point				*store(int fd);


#endif
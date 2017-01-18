/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 07:06:37 by rchoquer          #+#    #+#             */
/*   Updated: 2017/01/18 03:38:26 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// #include "../mlx/mlx.h"
# include <mlx.h>
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define ERROR  "Something went wrong"
# define FILE	"Error with input file"
# define BADARG "usage: ./fdf file"
# define PROPER "./fdf ended properly"

# define CX(x, z)	(x * 15 + (z * 0.65))
# define CY(y, z)	(y * 15 + (z * (0.65 / 2)))

# define X			iter->x
# define Y			iter->y
# define Z			iter->z

# define NX			iter->next->x
# define NY			iter->next->y
# define NZ			iter->next->z

# define LX			ln->x
# define LY			ln->y
# define LZ			ln->z

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

int					draw(t_env e, t_size size, t_point *points);
int					print_key(int keycode);
int					print_lst(t_point *node);
void				ft_exit(char *error);
void				lst_append(t_point **node, size_t x, size_t y, long z);
t_env				setup(char *name);
t_point				*nxtln(t_point *node);
t_point				*store(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 07:06:37 by rchoquer          #+#    #+#             */
/*   Updated: 2017/02/03 06:31:55 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define ERROR  "Something went wrong"
# define FILE	"Error with input file"
# define BADARG "usage: ./fdf file"
# define PROPER "./fdf ended properly"

# define X			iter->x
# define Y			iter->y
# define Z			iter->z

# define NX			iter->next->x
# define NY			iter->next->y
# define NZ			iter->next->z

# define LX			ln->x
# define LY			ln->y
# define LZ			ln->z

# define R			e->opt.color.r
# define G			e->opt.color.g
# define B			e->opt.color.b

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	size_t			full;
}					t_color;

typedef struct		s_draw
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_draw;

typedef struct		s_opt
{
	unsigned short	s;
	unsigned short	perspect;
	unsigned short	height;
	float			ct;
	float			ct_p;
	float			ctt;
	float			tmp;
	long			vert;
	long			horiz;
	t_color			color;
}					t_opt;

typedef struct		s_coord
{
	long			x;
	long			y;
}					t_coord;

typedef struct		s_point
{
	long			z;
	size_t			x;
	size_t			y;
	struct s_point	*next;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_opt			opt;
	t_coord			size;
	t_point			*head;
	size_t			x;
	size_t			y;
}					t_env;

int					hook_key(int keycode, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					expose_hook(t_env *e);
int					core(t_env *e, t_point *head);
int					recreate_img(t_env e);
void				colors(t_env *e, int key);
void				ft_exit(char *error);
void				draw(t_env e, t_point *iter);
void				drawline(t_coord origin, t_coord end, t_env e);
void				lst_append(t_point **node, size_t x, size_t y, long z);
t_coord				calc_point(int x, int y, int z, t_opt opt);
t_point				*nxtln(t_point *node);
t_point				*store(int fd, t_env *e);

#endif

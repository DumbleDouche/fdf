/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 07:06:37 by rchoquer          #+#    #+#             */
/*   Updated: 2016/12/11 10:59:15 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../libft/include/libft.h"

#ifndef FDF_H
#define FDF_H

typedef enum		STATUS
{
	EXIT = 0,
	ERROR = -1,
	BADARG = 2,
}					STATUS;


typedef struct		s_info
{
	void			*token;
	void			*window;
	struct s_info	*next;
}					t_info;

typedef struct		s_array
{
	int				elem;
	struct s_list	*next;
}					t_array;

int					draw(t_info *info);
int					ft_exit(STATUS current);
int					print_key(int keycode, void *info);
t_info				*setup(t_info *info);


#endif
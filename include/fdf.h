/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 07:06:37 by rchoquer          #+#    #+#             */
/*   Updated: 2016/12/11 07:42:10 by rchoquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

#ifndef FDF_H
#define FDF_H

typedef enum		STATUS
{
	EXIT = 0,
	ERROR = -1,
}					STATUS;


typedef struct		s_info
{
	void			*token;
	void			*window;
	struct s_info	*next;
}					t_info;

typedef struct		s_list
{
	int				elem;
	struct s_list	*next;
}					t_list;

#endif
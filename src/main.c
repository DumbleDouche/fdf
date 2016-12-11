#include <stdio.h>


#include "../include/fdf.h"

int				ft_exit(STATUS current)
{
	if (current == ERROR)
		exit (ERROR);
	exit (EXIT);
	return (1);
}

int		print_key(int keycode, void *param)
{
	(void)param;
	if (keycode == 53 || keycode == 36 || keycode == 76)
		exit (1);
	printf("key: %d\n", keycode);
	return (1);
}

int				setup(t_info *info)
{
	if ((info->token = mlx_init()) && (info->window = mlx_new_window(info->token, 500, 500, "Mon FDF")))
		return (0);
	return (1);
}

int				main(void)
{
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info));
	setup(info);
	
	mlx_key_hook(info->window, print_key, 0);
	mlx_loop(info->token);
	return (0);
}
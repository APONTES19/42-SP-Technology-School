#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			pos_x;
	int			pos_y;
}               t_window;

int		key_press(int key, t_window *window);
int			  close_window(t_window *window);
int move(int key, t_window *window);

int    main ()
{
	t_window    window;

	void	*img;
	int	img_x;
	int	img_y;

	window.pos_x = 0;
	window.pos_y = 0;

    window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, 400, 800, "My firt window");
    //mlx_key_hook(window.win_ptr, &key_press, &window);
	mlx_key_hook(window.win_ptr, &move, &window);

    mlx_hook(window.win_ptr, 33, 1L << 17, close_window, &window);

	img = mlx_xpm_file_to_image(window.mlx_ptr, "./img/falcon.xpm", &img_x, &img_y);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img, window.pos_x, window.pos_y);
	mlx_loop(window.mlx_ptr);
}

int close_window(t_window *window)
{
    mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(0);
}

int	key_press(int key, t_window *window)
{
	printf("key: %d", key);
	if (key == 65307)
		close_window(window);
}

int move(int key, t_window *window)
{
	printf("key: %d", key);
	if (key == 65363)
		window->pos_x += 1;
	else if (key == 65361)
		window->pos_y -= 1;
}

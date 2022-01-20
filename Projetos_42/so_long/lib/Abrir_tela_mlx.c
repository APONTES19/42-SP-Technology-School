#include <mlx.h>
#include <stdlib.h>

typedef struct window
{
    void         *mlx_ptr;
    void        *win_firt;
}                t_window;

int     key_press(int key, t_window *window);
int     close_window(t_window *window);

int     main ()
{
    t_window    window;
    window.mlx_ptr = mlx_init();
    window.win_firt = mlx_new_window(window.mlx_ptr, 400, 800, "My firt window");
    mlx_key_hook(window.win_firt, &key_press, &window);
    mlx_hook(window.win_firt, 33, 1L << 17, close_window, &window);
    mlx_loop(window.mlx_ptr);
}

int close_window(t_window *window)
{
    mlx_destroy_window(window->mlx_ptr, window->win_firt);
    exit(0);
}

int key_press(int key, t_window *window)
{
    if (key == 65307)
        close_window(window);
	return (0);
}

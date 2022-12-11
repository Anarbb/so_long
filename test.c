#include "mlx/mlx.h"
#include <stdio.h>
#include "./inc/libft.h"

// q: how to compile this including libft?
// gcc -Wall -Wextra -Werror -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit test.c

int deal_key(int key, void *param)
{
	(void) param;
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int main(void)
{
	void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_key_hook(win, deal_key, (void *)0);
	mlx_loop(mlx);
}
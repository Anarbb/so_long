#include <mlx.h>
#include <stdlib.h>

int main(void)
{
	void *mlx;
	void *win;
	void *img;
	int bpp;
	int endian;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx");
	img = mlx_xpm_file_to_image(mlx, "/Users/aarbaoui/Documents/1337/so_long/sprites/Ghosts/G/ghost_down2.xpm", &bpp, &endian);
	int i = 0;
	while (i < 100)
	{
		mlx_put_image_to_window(mlx, win, img, i, i);
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
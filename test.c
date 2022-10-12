#include "so_long.h"
/*
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_data {
	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;




void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y+1) * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/
/*
void  print_rectangle_plein(t_data img,  int lenght)
{
    int i = 0;
    int j = 0;
    while (i < lenght)
    {
        j = 0;
        while (j < lenght)
        {
            my_mlx_pixel_put(&img, 50 + i, 50 + j, 0x00FF0000);
            j++;
        }
        i++;
    }
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

    printf("img  = %p\n", img.addr);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

    print_rectangle_plein(img, 500);
   
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}

*/



/*
int print_image(int x, int y, t_vars *param)
{
    t_data	img;

    

    my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	mlx_put_image_to_window(param->mlx, param->win, img.img, 0, 0);
	//mlx_loop(mlx);

}  */


/*
int	close_window(int x, int y, t_vars *param)
{
    t_data	img;

    printf("(%d, %d)\n", x, y);
    img.img = mlx_new_image(param->mlx , 500, 500);
  
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

    my_mlx_pixel_put(&img, x, y, 0x00FF0000);  

    mlx_put_image_to_window(param->mlx, param->win, img.img, 0, 0);
    mlx_loop(param->mlx);
	return (0);
} 
 
  


int	main(void)
{
	t_data	img;
	t_vars	vars;

    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

    img.img = mlx_new_image(vars.mlx , 500, 500);
  
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

    mlx_hook(vars.win, 6, 1L<<6, close_window, &vars);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);  
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

*/


/*


int	close_window(int x, int y, t_data *vars) 
{
	int epais = 20;
	printf("(%d, %d)\n", x, y);
	int i = 0;
	my_mlx_pixel_put(vars, x, y, 0x00FF0000);
	while (i < epais)
	{
		my_mlx_pixel_put(vars, x + i, y, 0x00FF0000);
		my_mlx_pixel_put(vars, x + i, y + i, 0x00FF0000);
		my_mlx_pixel_put(vars, x + i, y - i, 0x00FF0000);

		my_mlx_pixel_put(vars, x - i, y , 0x00FF0000);
		my_mlx_pixel_put(vars, x - i, y + i , 0x00FF0000);
		my_mlx_pixel_put(vars, x - i, y - i, 0x00FF0000);

		my_mlx_pixel_put(vars, x, y + i, 0x00FF0000);
		my_mlx_pixel_put(vars, x + i, y + i, 0x00FF0000);
		my_mlx_pixel_put(vars, x - i, y + i, 0x00FF0000);

		my_mlx_pixel_put(vars, x, y - 1, 0x00FF0000);
		my_mlx_pixel_put(vars, x + i, y - 1, 0x00FF0000);
		my_mlx_pixel_put(vars, x - i, y - 1, 0x00FF0000);
		i++;
	}
	
	

	mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> img, 0, 0);
}

int	main(void)
{
	t_data vars;


	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);

	mlx_hook(vars.win, 6, 1L<<6, close_window, &vars);
	mlx_loop(vars.mlx);
}


*/

/*
int	main(void)
{
	void	*mlx;
	void 	*win;
	void	*img;
	char	*relative_path = "images/buritos.xpm";
	int		img_width;
	int		img_height;
	int i = 0;
	int j = 0;

	mlx = mlx_init();


	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	win = mlx_new_window(mlx, img_width * 15, img_height * 15, "Hello world!");
	while (i < img_width * 15)
	{
		
		printf("(%d, %d)\n", img_width * 14, i);
		mlx_put_image_to_window(mlx, win, img, i, 0);
		mlx_put_image_to_window(mlx, win, img, 0, i);
		mlx_put_image_to_window(mlx, win, img, img_width * 14, i);
		mlx_put_image_to_window(mlx, win, img, i, img_height * 14);
		i += img_width;
	}
	mlx_loop(mlx);
} */

#include "so_long.h"

void print_vars(t_vars *vars)
{
    printf("***********************\n");
    printf("mlx = %p\n***********************\n", vars -> mlx);
    printf("win = %p\n***********************\n", vars -> win);
    
    printf("map:\n");
    print_tab(vars -> map);
    printf("***********************\n");
    printf("player = %p\n***********************\n", vars -> player);
    printf("player_x = %d\n***********************\n", vars -> player -> x);
    printf("player_y = %d\n***********************\n", vars -> player -> y);
    printf("player_c = %d\n***********************\n", vars -> player -> collectible);
    printf("sprite = %p\n***********************\n\n\n", vars -> sprite);
    if (vars -> sprite != NULL)
    {
        printf("img_1 = %p\n***********************\n", vars -> sprite -> img_1);
        printf("img_0 = %p\n***********************\n", vars -> sprite -> img_0);
        printf("img_p = %p\n***********************\n", vars -> sprite -> img_p);
        printf("img_c = %p\n***********************\n", vars -> sprite -> img_c);
        printf("img_e = %p\n***********************\n", vars -> sprite -> img_e);
    }
}

int give_height(char **map)
{
    int i;
    i = 0;
    while (map[i] != NULL)
        i++;
    return (i);
}


int give_width(char **map)
{
    int i;

    i = 0;
    while (map[0][i])
        i++;
    return (i);
}

int window_image(t_vars *vars)
{
    int i;
    int j;
    int		img_width;
	int		img_height;

    
    i = 0;
    while (vars -> map[i] != NULL)
    {
        j = 0;
        while (vars -> map[i][j])
        {
          
            if (vars -> map[i][j] == '1')
                mlx_put_image_to_window(vars->mlx, vars-> win, vars -> sprite -> img_1, j * 33, i * 33);
            if (vars -> map[i][j] == '0')
                mlx_put_image_to_window(vars->mlx, vars-> win, vars -> sprite -> img_0, j * 33, i * 33);
            if (vars -> map[i][j] == 'C')
                mlx_put_image_to_window(vars->mlx, vars-> win, vars -> sprite -> img_c, j * 33, i * 33);
            if (vars -> map[i][j] == 'E')
                mlx_put_image_to_window(vars->mlx, vars-> win, vars -> sprite -> img_e, j * 33, i * 33);
            if (vars -> map[i][j] == 'P')
                mlx_put_image_to_window(vars->mlx, vars-> win, vars -> sprite -> img_p, j * 33, i * 33);
            j++;
        }
        i++; 
    }
    return (0);
}

 
void move_col(char **map, t_vars *vars, int move)
{
    if (map[vars->player->x][(vars->player->y) + move] != '1')
    {
        if (map[vars->player->x][(vars->player->y) + move] == 'C')
        {
            (vars->player->collectible)--;
        }
        if (map[vars->player->x][(vars->player->y) + move] == 'E' && vars->player->collectible != 0)
            return;
        map[vars->player->x][(vars->player->y)] = '0';
        map[vars->player->x][(vars->player->y) + move] = 'P';
        vars->player->y += move;
    }
    
}

void move_line(char **map, t_vars *vars, int move)
{
    if (map[(vars->player->x) + move][(vars->player->y)] != '1')
    {
        if (map[(vars->player->x) + move][(vars->player->y)] == 'C')
        {
            (vars->player->collectible)--;
        }
        if (map[(vars->player->x) + move][(vars->player->y)] == 'E' && vars->player->collectible != 0)
            return;
        map[(vars->player->x)][(vars->player->y)] = '0';
        map[(vars->player->x) + move][(vars->player->y)] = 'P';
        vars->player->x += move;
    }

}


int move_control(int keycode, t_vars *vars)
{
    char **map;

    map = vars ->map;
    if (keycode == 119)
        move_line(map, vars, -1);
    if (keycode == 100)
        move_col(map, vars, +1);
    if (keycode == 97)
        move_col(map, vars, -1);
    if (keycode == 115)
        move_line(map, vars, +1);
    window_image(vars);
    
    return (0); 
} 

int print_window(t_vars *vars)
{
    //print_vars(vars);
    //print_tab(vars->map);
    window_image(vars);
    //print_vars(vars);
    mlx_key_hook(vars->win, move_control, vars);
    // mlx_hook(vars->win, 2, (1L<<0), move_control, &vars);
    //mlx_loop_hook(vars->mlx, window_image, &vars);
    mlx_loop(vars->mlx);
}
 
/*
int main(void)
{

    char    **map;
    map = create_map("map_1.ber");
    if (map == NULL)
    {
        free_tab(map);
        return (0);
    }
    if (!parsing_map(map))
    {
        print_tab(map);
        //free_tab(map);
        printf("La map est incorrect\n");
    }
    else
    {
        printf("La map est correct\n");
        print_tab(map);
        print_window(map);
    }
    free_tab(map);
}*/
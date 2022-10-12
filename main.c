#include "so_long.h"


int count_collectible(char **map)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}


t_player    *create_player(char **map)
{
    t_player *player;

    player = malloc(sizeof(player));
    if (!player)
        return (NULL);
    search_cord(map, 'P', &player -> x, &player -> y);
    player -> collectible = count_collectible(map);
    return(player);
}

t_env *create_sprite(void *mlx)
{
    t_env *sprite;

    int img_width;
    int img_height;

    img_width = 0;
    img_width = 0;
    sprite = malloc(sizeof(sprite));
    if (!sprite)
        return (NULL);
    sprite -> img_1 = mlx_xpm_file_to_image(mlx, "images/1.xpm", &img_width, &img_height);
    sprite -> img_0 = mlx_xpm_file_to_image(mlx, "images/0.xpm", &img_width, &img_height); 
    sprite -> img_c = mlx_xpm_file_to_image(mlx, "images/c.xpm", &img_width, &img_height);
    sprite -> img_e = mlx_xpm_file_to_image(mlx, "images/e.xpm", &img_width, &img_height);
    sprite -> img_p = mlx_xpm_file_to_image(mlx, "images/p.xpm", &img_width, &img_height);
    return (sprite);
}

t_vars *create_vars(char **map)
{
    t_vars *vars;

    vars = malloc(sizeof(vars));
    if (!vars)
        printf("malloc vars echoue\n");
    vars -> mlx = malloc(sizeof(vars->mlx));
    if (!vars ->mlx)
        printf("malloc vars -> mlx echoue\n");
    vars -> mlx = NULL;
    vars -> mlx = mlx_init();
    //printf("vars = %p\n", vars->mlx);
    
    vars -> win = malloc(sizeof(vars->win));
    if (!vars ->win)
        printf("malloc vars -> win echoue\n");
    vars -> win = NULL;
    vars->win = mlx_new_window(vars->mlx, give_width(map) * 33, give_height(map) * 33, "Hello world!");
    //printf("vars = %p\n", vars->win);

    
    vars->map = map_copy(map);
    if (!vars->map)
        printf("malloc vars ->map echouer\n");
    //print_tab(vars->map);
    vars->player = create_player(map);
    if (!vars->player)
        printf("malloc vars ->player echouer\n");
    //printf("(%d, %d) = %d\n", vars->player -> x, vars ->player -> y, vars->player -> collectible);
    vars ->sprite =NULL;
    vars->sprite = create_sprite(vars->mlx);
    if (!vars -> sprite)
        printf("malloc echouer vars->sprite\n");
    //printf("%p\n", vars->sprite->img_e);
    free(map);
    return(vars);
} 


int main(void)
{
    char    **map;
    t_vars *vars;

    map = create_map("map_1.ber");
    if (map == NULL)
    {
        printf("malloc map echouer\n");
        free_tab(map);
        return (0);
    }
    if (!parsing_map(map))
    {
        //print_tab(map);
        //free_tab(map);
        printf("La map est incorrect\n");
    }
    else
    {
        printf("La map est correct\n");
        vars = create_vars(map);
        
        print_window(vars);
    }
    //free_tab(map); 
} 
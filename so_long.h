#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "mlx_linux/mlx.h"
#define BUFFER_SIZE 5

// gcc -D BUFFER_SIZE=4 *.c get_next_line/*.c

typedef struct s_player
{
    int x;
    int y;
    int collectible;
}              t_player;

typedef struct s_env
{
	void *img_1;
	void *img_0;
	void *img_p;
	void *img_c;
	void *img_e;
}              t_env;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    char **map;
    t_player *player;
	t_env *sprite;
}				t_vars;

/* backtracking.c */

int check_line(char **map, int x, int y,int move);
int check_col(char **map, int x, int y, int move);
int bloque(char **map, int x, int y);
int check_case_neighbour(char **map, int x, int y, char l);
void backtracking(char **map, int x, int y);

/* utils_backtracking */

int ft_strchr(char c, char *str);
int search_cord(char **map,char search, int *x, int *y);
char *ft_strdup(char *str);
char **map_copy(char **map);

/* read_map.c */

char *create_big_line(char *str, int *height);
char    *create_word(char *big_line); // mettre dans un fichier split
char    **so_long_split(char *big_line, int height);
char    **create_map(char *str);

/* parsing.c */

int check_wall(char **map);
int check_other(char **map);
int parsing_map(char **map);
int check_exit(char **map, int x, int y);
int compare_map(char **map, char **cpy);

/* utils_parsing.c */

int check_rectangle(char **map);
void    check_all_unique(char **map, int *sortie, int *start, int *items);
int check_unique(char **map);
int check_wall_col(char **map, int col, int height);
int check_wall_line(char **map, int line);


/* utils.c */

void    print_tab(char **map);  // a supp
int ft_len_char_tab(char **map);
void    free_tab(char **map);

/* split_long.c a enlever avant la soutenance */

char    *create_word(char *big_line);
char    **so_long_split(char *big_line, int height);

/* window.c */

int set_texture(t_vars *vars);
int give_height(char **map);
int give_width(char **map);
int print_window(t_vars *vars);
int window_image(t_vars *vars);

#endif

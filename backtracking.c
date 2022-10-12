#include "so_long.h"


int check_line(char **map, int x, int y, int move)
{
        if (map[x][y + move] != 'E' && map[x][y + move] != '1' && map[x][y +move] != 'X')
        {
            map[x][y + move] = 'X';
            return (1);
        }
   
    return (0);
}

int check_col(char **map, int x, int y, int move)
{
        if (map[x + move][y] != 'E' && map[x + move][y] != '1' && map[x + move][y] != 'X' )
        {
            map[x + move][y]= 'X';
            return (1);
        }
    return (0);
}



int bloque(char **map, int x, int y)
{
    if (ft_strchr(map[x][y + 1], "1XE"))
    {
        if (ft_strchr(map[x][y - 1], "1XE"))
        {
            if (ft_strchr(map[x + 1][y], "1XE"))
            {
                if (ft_strchr(map[x - 1][y], "1XE"))                  
                    return (1);
            }
        }
    }
    return (0);
}

/* regarde dans les case voisine si elle trouve l sers a savoir si on trouve un x ou non*/

int check_case_neighbour(char **map, int x, int y, char l) 
{
    if (map[x][y + 1] && map[x][y + 1] == l)
        return(1);
    if (map[x - 1][y] && map[x - 1][y] == l)
        return(1);
    if (map[x + 1][y] && map[x + 1][y] == l)
        return(1);
    if (map[x][y - 1] && map[x][y - 1] == l)
        return(1);
    return (0);
}

void backtracking(char **map, int x, int y) // regarder cette merde 
{
    if (bloque(map, x, y))
        return;
    map[x][y] = 'X';
    if (check_col(map, x, y, +1))
        backtracking(map, x + 1, y);
    if (check_line(map, x, y, -1))
        backtracking(map, x, y - 1);
    if (check_col(map, x, y, -1))
        backtracking(map, x - 1, y);
    if (check_line(map, x, y, +1))
        backtracking(map, x, y + 1);
}


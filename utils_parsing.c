#include "so_long.h"

int check_rectangle(char **map)
{
    int i;
    int j;
    
    i = 0;
    while (map[i] != 0)
    {
        j = i + 1;
        while (map[j] != 0)
        {
            if (ft_strlen(map[i]) != ft_strlen(map[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    check_all_unique(char **map, int *sortie, int *start, int *items)
{
    int i;
    int j;

    i = 0;
    *sortie = 0;
    *start = 0;
    *items = 0;
    while (map[i] != 0)
    {
        j = 0;
    
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                *sortie += 1;
            if (map[i][j] == 'C')
                *items += 1;
            if (map[i][j] == 'P')
                *start += 1;
            j++;
        }
        i++;
    }
}

int check_unique(char **map)
{
    int sortie;
    int start;
    int items;

    check_all_unique(map, &sortie, &start, &items);
    if (sortie != 1)
        return (0);
    if (start != 1)
        return (0);
    if (items < 1)
        return (0);
    return (1);
}
int check_wall_col(char **map, int col, int height)
{
    int i;

    i = 0;
    while (i < height)
    {
        if (map[i][col] && map[i][col] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_wall_line(char **map, int line)
{
    int j;
    int len;

    j = 0;
    len = ft_strlen(map[line]);
    while (j < len)
    {
        if ( map[line][j] && map[line][j] != '1')
            return (0);
        j++;
    }
    return (1);
}
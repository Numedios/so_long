/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelabba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:06:43 by sbelabba          #+#    #+#             */
/*   Updated: 2022/09/13 16:06:44 by sbelabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int check_wall(char **map)
{
    int height;

    height = ft_len_char_tab(map);

    if (!check_wall_col(map, 0, height) || !check_wall_col(map, ft_strlen(map[0]) - 1, height))
        return (0);
    if (!check_wall_line(map, 0) || !check_wall_line(map, height))
        return (0);
    return(1);
}   

int check_other(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j])
        {
            if (!((map[i][j] == '0' || map[i][j] == '1') || ((map[i][j] == 'E' || map[i][j] == 'C') || map[i][j] == 'P')))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}


int check_exit(char **map, int x, int y)
{
    if (map[x][y + 1] == 'X')
        return (1);
    if (map[x][y - 1] == 'X')
        return (1);
    if (map[x + 1][y] == 'X')
        return (1);
    if (map[x - 1][y] == 'X')
        return (1);
    return (0);
}

int compare_map(char **map, char **cpy)
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j])
        {
            if ((map[i][j] == 'C' && cpy[i][j] != 'X') || (map[i][j] == 'E' && !check_exit(cpy, i, j)))
            {
                free_tab(cpy);
                return (0);
            }
            j++;
        }
        i++;
    }
   
    free_tab(cpy);
    return (1);
}


int parsing_map(char **map)
{
    int x;
    int y;
    char **cpy;

    if (!check_rectangle(map))
        return (0);
    if (!check_unique(map))
        return (0);
    if (!check_wall(map))
        return (0);
    if (!check_other(map))
        return (0);
    
    cpy = map_copy(map);
    
    search_cord(cpy, 'P', &x, &y);
   
    backtracking(cpy, x, y);
 
    if (!compare_map(map, cpy))
        return (0);
    printf("ici\n");
    return (1);
}

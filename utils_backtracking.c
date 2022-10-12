
#include "so_long.h"

int ft_strchr(char c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}


int search_cord(char **map,char search, int *x, int *y)
{
    int i;
    int j;
    i = 0;
    while (map[i] != 0)
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == search)
            {
                *x = i;
                *y = j;
                return (1);
            }
            j++;
        }
        i++;
    }
    return(0);
}

char *ft_strdup(char *str)
{
    char *res;
    int i;

    i = 0;
    res = malloc(sizeof(char) * (ft_strlen(str) + 1));
    while (str[i])
    {
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

char **map_copy(char **map)
{
    char **cpy;
    int i;

    i = 0;
    cpy = malloc(sizeof(char *) * (ft_len_char_tab(map) + 1));
    
    while (map[i] != NULL)
    {
        cpy[i] = ft_strdup(map[i]);
        i++;
    }
    cpy[i] = 0;
    return (cpy);
}


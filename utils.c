#include "so_long.h"


/* a enlever */ 
void    print_tab(char **map)
{
    int i;
    
    i = 0;
    while (map[i] != NULL)
    {
        printf("%s\n", map[i]);
        i++;
    }
    printf("\n");
}


int ft_len_char_tab(char **map)
{
    int i;

    i = 0;
    while(map[i] != NULL)
    {
        i++;
    }
    return (i);
}

void    free_tab(char **map)
{
    int i;
    
    i = 0;
    if (!map)
        return;
    while (map && map[i] != NULL)
        free(map[i++]);
    if (map != NULL)
        free(map);
}

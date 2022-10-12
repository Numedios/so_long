#include "so_long.h"


char    *create_word(char *big_line)
{
    int i;
    int j;
    char    *word;

    i = 0;
    while (big_line[i] && big_line[i] != '\n')
        i++;
    word = malloc(sizeof(char) * (i + 1));
    if (!word)
        return (NULL);
    j = 0;
    while (i > j)
    {
        word[j] = big_line[j];
        j++;
    }
    word[j] = '\0';
    return (word);
}

char    **so_long_split(char *big_line, int height)
{
    char    **map;
    int i;

    i = 0;
    map = malloc(sizeof(char *) * (height + 1));
    if (!map)
        return (NULL);
        
    while (big_line && *big_line)
    {

        while (*big_line && *big_line == '\n')
        {
            big_line++;
           
        }
        if (*big_line && *big_line != '\n')
        {
            map[i++] = create_word(big_line);
            //if (map[i])
            //    return (free_tab(map), NULL);
        }
        while (*big_line && *big_line != '\n')
            big_line++;
    }
    map[i] = 0;
    return (map);
}

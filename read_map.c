#include "so_long.h"

char *create_big_line(char *str, int *height)
{
    int fd;
    char *big_line;
    char *line;
    int c;
     
    c = 0;
    big_line = NULL;
    fd = open(str, 00400);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            
            free(line); // a re verifier
            break;
        }
        c++;
        big_line = ft_strjoin(big_line, line);
        free(line);
    }
    close(fd);
    *height = c;
	return(big_line);
}

int check_big_line(char *big_line)
{
    int i;
    int j;

    i = 0;
    j = 1;

    if (big_line == NULL)
    {
        free(big_line);
        return (0);
    }
    while (big_line && big_line[j])
    {
        if (big_line[i] == '\n' && big_line[j] == '\n')
            return (0);
        i++;
        j++;
    }
    if (big_line && big_line[j - 1] == '\n')
        return (0);
    return (1);
}

char    **create_map(char *str)
{

    char *big_line;
    int height;
    char    **map;

    big_line = create_big_line(str, &height);
      
    if (!big_line)
    {
        free(big_line); // a re verifier
        return (NULL);
    }
    if (check_big_line(big_line))
    {
        map = so_long_split(big_line, height);
        if (!map)
        {
            free_tab(map);
            return(free(big_line), NULL);
        }
        free(big_line);
        return (map);
    }
    free(big_line);
    return (NULL);
}
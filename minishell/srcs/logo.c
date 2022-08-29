#include "../includes/minishell.h"

int logo(void)
{
    int fd;
    char *logo;

    logo = (char*)ft_calloc(700, sizeof(char *));
    fd = open("logo.txt",O_RDONLY);
    if (fd < 0)
        return(1);
    while(read(fd,logo,1))
        printf("%s",logo);
    close(fd);
    free((char*)logo);
    return (0);
}
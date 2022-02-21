#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strchr( const char *str, int ch);

int main()
{
    char    s1[] = "palavra";
    char    *l;
    char    *t;
    l = ft_strchr(s1,'a');
    t = strchr(s1,'a');
    printf("%c\n",*l);
    printf("%c\n\n",*(l+1));
    printf("%c\n",*t);
    printf("%c\n",*(t+1));
    return (0);
}

char    *ft_strchr(const char *str, int ch)
{
    while (*str != ch)
    {
        if (*str == '\0')
            return (0);
        str++;
    }
    return ((char *)str);
}







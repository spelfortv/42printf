#include "ft_printf.h"

size_t  ft_strlen(const char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}

static char     *numtochar(int n, long divider, char *ret)
{
        int     i;

        i = 0;
        if (n < 0)
        {
                i = 1;
                ret[0] = '-';
                n *= -1;
        }
        while (divider > 0)
        {
                ret[i] = (n / divider) % 10 + '0';
                divider /= 10;
                i++;
        }
        ret[i] = '\0';
        return (ret);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dsize)
{
        size_t  ssize;
        size_t  i;

        i = 0;
        ssize = ft_strlen(src);
        if (dsize != 0)
        {
                dsize--;
                while (src[i] != '\0' && dsize > 0)
                {
                        dst[i] = src[i];
                        dsize--;
                        i++;
                }
                dst[i] = '\0';
        }
        return (ssize);
}

char    *ft_itoa(int n)
{
        int             i;
        long    divider;
        char    *ret;

        i = 1;
        divider = 1;
        if (n < 0)
                i++;
        while (n / divider >= 10 || n / divider <= -10)
        {
                i++;
                divider *= 10;
        }
        ret = malloc(sizeof(char) * i + 1);
        if (!ret)
                return (NULL);
        if (n == -2147483648)
        {
                ft_strlcpy(ret, "-2147483648", ft_strlen("-2147483648") + 1);
                return (ret);
        }
        ret = numtochar(n, divider, ret);
        return (ret);
}

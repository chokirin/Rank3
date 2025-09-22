
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *buf, *p, *found;
    char c;
    int i = 0, size = 1024, len, ret;
    
    if (argc != 2 || !argv[1][0])
        return 1;
    
    len = strlen(argv[1]);
    buf = malloc(size);
    if (!buf) 
	{
        fprintf(stderr, "Error: malloc failed\n");
        return 1;
    }
    
    while ((ret = read(0, &c, 1)) > 0) 
	{
        if (i >= size - 1) 
		{
            size *= 2;
            buf = realloc(buf, size);
            if (!buf) {
                fprintf(stderr, "Error: realloc failed\n");
                return 1;
            }
        }
        buf[i++] = c;
    }
    if (ret < 0) {
        perror("Error");
        return 1;
    }
    buf[i] = 0;
    
    p = buf;
    while ((found = memmem(p, strlen(p), argv[1], len))) 
	{
        *found = 0;
        printf("%s", p);
        for (int j = 0; j < len; j++)
            printf("*");
        p = found + len;
    }
    printf("%s", p);
    
    free(buf);
    return 0;
}

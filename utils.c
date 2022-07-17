#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getProgramName(char *path)
{
    int begin = 0;
    int n = strlen(path);
    for (int i = 0; i < n; i++)
    {
        if (path[i] == '/' || path[i] == '\\')
        {
            begin = i+1;
        }
    }
    char *name = (char *)calloc(n - begin, sizeof(char));
    strcpy(name, &path[begin]);
    return name;
}

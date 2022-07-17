#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "SSTConfig.h"

int main(int argc, char *argv[])
{
    char *programName = getProgramName(argv[0]);
    if (argc == 1)
    {
        goto help;
    }

    if (strcmp(argv[1], "-v") == 0)
    {
        printf("SST Version %d.%d", SST_VERSION_MAJOR, SST_VERSION_MINOR);
    }
    else if (strcmp(argv[1], "-a") == 0)
    {
    }
    else if (strcmp(argv[1], "-t") == 0)
    {
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
    }
    else
    {
    help:
        printf("SST: Windows scheduled shutdown tool\n");
        printf("Usage:\n");
        printf("%s -h:show usage information\n", programName);
        printf("%s -v:show version number\n", programName);
        printf("%s -a hh:mm:ss:shutdown at next hh:mm:ss\n", programName);
        printf("%s -t hh:mm:ss:shutdown after hh:mm:ss\n", programName);
        printf("%s -c:cancel shutdown plan\n", programName);
    }
}
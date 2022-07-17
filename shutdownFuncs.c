#include "shutdownFuncs.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int shutdown_at(char *timeString)
{
    int hour;
    int minute;
    int second;
    time_t now_secs;
    time_t schedule_secs;
    struct tm *now_time;
    struct tm *schedule_time;
    double timeInterval;
    int loadedtime;
    char command[21];

    loadedtime = sscanf(timeString, "%d:%d:%d", &hour, &minute, &second);
    if (loadedtime != 3)
    {
        return -1;
    }
    schedule_time = (struct tm *)malloc(sizeof(struct tm));
    now_secs = time(NULL);
    now_time = localtime(&now_secs);
    memcpy(schedule_time, now_time, sizeof(struct tm));

    schedule_time->tm_hour = hour;
    schedule_time->tm_min = minute;
    schedule_time->tm_sec = second;

    schedule_secs = mktime(schedule_time);
    timeInterval = difftime(schedule_secs, now_secs);
    if (timeInterval < 0)
    {
        schedule_time->tm_mday += 1;
        schedule_secs = mktime(schedule_time);
        timeInterval = difftime(schedule_secs, now_secs);
    }
    
    sprintf(command, "shutdown -s -t %d", (int)timeInterval);
    system(command);
    return 0;
}

int shutdown_after(char *timeString)
{
    int hour;
    int minute;
    int second;
    time_t now_secs;
    time_t schedule_secs;
    struct tm *now_time;
    struct tm *schedule_time;
    double timeInterval;
    int loadedtime;
    char command[21];

    loadedtime = sscanf(timeString, "%d:%d:%d", &hour, &minute, &second);
    if (loadedtime != 3)
    {
        return -1;
    }
    schedule_time = (struct tm *)malloc(sizeof(struct tm));
    now_secs = time(NULL);
    now_time = localtime(&now_secs);
    memcpy(schedule_time, now_time, sizeof(struct tm));

    schedule_time->tm_hour += hour;
    schedule_time->tm_min += minute;
    schedule_time->tm_sec += second;

    schedule_secs = mktime(schedule_time);
    timeInterval = difftime(schedule_secs, now_secs);

    sprintf(command, "shutdown -s -t %d", (int)timeInterval);
    system(command);
    return 0;
}

void shutdown_cancel()
{
    system("shutdown -a");
}

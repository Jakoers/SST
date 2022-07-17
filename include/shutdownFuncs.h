#ifndef SHUTDOWNFUNCS
#define SHUTDOWNFUNCS

/**
 * 在指定时间关机
 * @param timeString 格式为hh:mm:ss的表示时间的字符串
 * @return 0表示正常执行，-1表示时间timeString格式有误
 */
int shutdown_at(char *timeString);


/**
 * 在指定时间后关机
 * @param timeString 格式为hh:mm:ss的表示时间的字符串
 * @return 0表示正常执行，-1表示时间timeString格式有误
 */
int shutdown_after(char *timeString);


/**
 * 取消关机
 */
void shutdown_cancel();

#endif
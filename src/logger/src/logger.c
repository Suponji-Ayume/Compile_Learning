#include "logger/logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 静态全局变量
static FILE *log_file = NULL;
static LogLevel current_level = LOG_INFO;
static char log_path[256] = {0};

/**
 * 获取当前时间字符串
 */
static const char *get_current_time(void)
{
    static char time_str[64];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);
    return time_str;
}

/**
 * 获取日志级别字符串
 */
static const char *get_level_str(LogLevel level)
{
    switch (level)
    {
    case LOG_DEBUG:
        return "DEBUG";
    case LOG_INFO:
        return "INFO ";
    case LOG_WARN:
        return "WARN ";
    case LOG_ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

/**
 * 初始化日志系统
 */
void logger_init(const char *log_file_path, LogLevel level)
{
    // 设置日志文件路径
    if (log_file_path)
    {
        strncpy(log_path, log_file_path, sizeof(log_path) - 1);
    }
    else
    {
        strcpy(log_path, "app.log");
    }

    // 设置日志级别
    current_level = level;

    // 打开日志文件
    log_file = fopen(log_path, "a");
    if (!log_file)
    {
        fprintf(stderr, "无法打开日志文件: %s\n", log_path);
    }
    else
    {
        logger_info("日志系统初始化成功，日志文件: %s，日志级别: %s", log_path, get_level_str(current_level));
    }
}

/**
 * 实际的日志记录函数（内部使用）
 */
static void log_message(LogLevel level, const char *format, va_list args)
{
    if (level < current_level)
        return;

    const char *time_str = get_current_time();
    const char *level_str = get_level_str(level);

    // 输出到控制台
    fprintf(stdout, "[%s] [%s] ", time_str, level_str);
    va_list args_copy;
    va_copy(args_copy, args);
    vfprintf(stdout, format, args_copy);
    va_end(args_copy);
    fprintf(stdout, "\n");
    fflush(stdout);

    // 输出到日志文件
    if (log_file)
    {
        fprintf(log_file, "[%s] [%s] ", time_str, level_str);
        va_copy(args_copy, args);
        vfprintf(log_file, format, args_copy);
        va_end(args_copy);
        fprintf(log_file, "\n");
        fflush(log_file);
    }
}

/**
 * 可变参数日志记录函数
 */
void logger_log(LogLevel level, const char *message, ...)
{
    va_list args;
    va_start(args, message);
    log_message(level, message, args);
    va_end(args);
}

/**
 * 调试日志
 */
void logger_debug(const char *message, ...)
{
    va_list args;
    va_start(args, message);
    log_message(LOG_DEBUG, message, args);
    va_end(args);
}

/**
 * 信息日志
 */
void logger_info(const char *message, ...)
{
    va_list args;
    va_start(args, message);
    log_message(LOG_INFO, message, args);
    va_end(args);
}

/**
 * 警告日志
 */
void logger_warn(const char *message, ...)
{
    va_list args;
    va_start(args, message);
    log_message(LOG_WARN, message, args);
    va_end(args);
}

/**
 * 错误日志
 */
void logger_error(const char *message, ...)
{
    va_list args;
    va_start(args, message);
    log_message(LOG_ERROR, message, args);
    va_end(args);
}

/**
 * 关闭日志系统
 */
void logger_shutdown(void)
{
    if (log_file)
    {
        logger_info("日志系统关闭");
        fclose(log_file);
        log_file = NULL;
    }
}

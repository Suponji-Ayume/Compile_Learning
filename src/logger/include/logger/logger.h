#ifndef LOGGER_H
#define LOGGER_H

#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * 日志级别
     */
    typedef enum
    {
        LOG_DEBUG, // 调试信息
        LOG_INFO,  // 普通信息
        LOG_WARN,  // 警告信息
        LOG_ERROR  // 错误信息
    } LogLevel;

    /**
     * 初始化日志系统
     * @param log_file_path 日志文件路径（NULL表示使用默认路径）
     * @param level 日志级别
     */
    void logger_init(const char *log_file_path, LogLevel level);

    /**
     * 记录日志（可变参数版本）
     * @param level 日志级别
     * @param message 格式化字符串
     * @param ... 可变参数
     */
    void logger_log(LogLevel level, const char *message, ...);

    /**
     * 记录调试日志
     */
    void logger_debug(const char *message, ...);

    /**
     * 记录信息日志
     */
    void logger_info(const char *message, ...);

    /**
     * 记录警告日志
     */
    void logger_warn(const char *message, ...);

    /**
     * 记录错误日志
     */
    void logger_error(const char *message, ...);

    /**
     * 关闭日志系统
     */
    void logger_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif

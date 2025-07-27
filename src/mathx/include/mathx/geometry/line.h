#ifndef MATHX_GEOMETRY_LINE_H
#define MATHX_GEOMETRY_LINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "point.h"

/**
 * 线段结构体
 */
typedef struct {
    Point start;  // 起点
    Point end;    // 终点
} Line;

/**
 * 创建线段
 * @param start 起点指针
 * @param end 终点指针
 * @return 新创建的线段
 */
Line line_create(const Point* start, const Point* end);

/**
 * 计算线段长度
 * @param line 线段指针
 * @return 长度
 */
double line_length(const Line* line);

/**
 * 判断点是否在线段上
 * @param p 点指针
 * @param line 线段指针
 * @return 1-在线段上，0-不在线段上
 */
int point_on_line(const Point* p, const Line* line);

/**
 * 打印线段
 * @param line 线段指针
 */
void line_print(const Line* line);

#ifdef __cplusplus
}
#endif

#endif

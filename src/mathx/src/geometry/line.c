#include <stdio.h>
#include <math.h>
#include "line.h"

/**
 * 创建线段
 */
Line line_create(const Point* start, const Point* end) {
    Line line;
    if (start) line.start = *start;
    if (end) line.end = *end;
    return line;
}

/**
 * 计算线段长度
 */
double line_length(const Line* line) {
    if (!line) return 0.0;
    return point_distance(&line->start, &line->end);
}

/**
 * 判断点是否在线段上（简化版）
 */
int point_on_line(const Point* p, const Line* line) {
    if (!p || !line) return 0;
    
    // 简化判断：检查点是否在由线段形成的矩形内
    double min_x = (line->start.x < line->end.x) ? line->start.x : line->end.x;
    double max_x = (line->start.x > line->end.x) ? line->start.x : line->end.x;
    double min_y = (line->start.y < line->end.y) ? line->start.y : line->end.y;
    double max_y = (line->start.y > line->end.y) ? line->start.y : line->end.y;
    
    return (p->x >= min_x && p->x <= max_x && p->y >= min_y && p->y <= max_y);
}

/**
 * 打印线段信息
 */
void line_print(const Line* line) {
    if (!line) {
        printf("Line(NULL)\n");
        return;
    }
    
    printf("Line from ");
    point_print(&line->start);
    printf(" to ");
    point_print(&line->end);
}

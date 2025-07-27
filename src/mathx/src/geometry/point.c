#include <stdio.h>
#include <math.h>
#include "point.h"

/**
 * 创建点
 */
Point point_create(double x, double y) {
    Point p = {x, y};
    return p;
}

/**
 * 计算两点之间的距离
 */
double point_distance(const Point* a, const Point* b) {
    if (!a || !b) return 0.0;
    
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    return sqrt(dx * dx + dy * dy);
}

/**
 * 点加法
 */
Point point_add(const Point* a, const Point* b) {
    Point result = {0.0, 0.0};
    if (a && b) {
        result.x = a->x + b->x;
        result.y = a->y + b->y;
    }
    return result;
}

/**
 * 点减法
 */
Point point_subtract(const Point* a, const Point* b) {
    Point result = {0.0, 0.0};
    if (a && b) {
        result.x = a->x - b->x;
        result.y = a->y - b->y;
    }
    return result;
}

/**
 * 打印点信息
 */
void point_print(const Point* p) {
    if (p) {
        printf("Point(%.2f, %.2f)\n", p->x, p->y);
    } else {
        printf("Point(NULL)\n");
    }
}

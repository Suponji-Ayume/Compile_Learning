#ifndef MATHX_GEOMETRY_POINT_H
#define MATHX_GEOMETRY_POINT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 二维点结构体
 */
typedef struct {
    double x;   // x坐标
    double y;   // y坐标
} Point;

/**
 * 创建点
 * @param x x坐标
 * @param y y坐标
 * @return 新创建的点
 */
Point point_create(double x, double y);

/**
 * 计算两点之间的距离
 * @param a 第一个点
 * @param b 第二个点
 * @return 距离
 */
double point_distance(const Point* a, const Point* b);

/**
 * 点加法
 * @param a 第一个点
 * @param b 第二个点
 * @return 结果点
 */
Point point_add(const Point* a, const Point* b);

/**
 * 点减法
 * @param a 第一个点
 * @param b 第二个点
 * @return 结果点
 */
Point point_subtract(const Point* a, const Point* b);

/**
 * 打印点
 * @param p 点指针
 */
void point_print(const Point* p);

#ifdef __cplusplus
}
#endif

#endif

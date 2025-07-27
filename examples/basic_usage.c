#include "logger/logger.h"
#include "mathx/mathx.h"
#include <stdio.h>

void print_matrix(const Matrix *mat, const char *name)
{
    printf("%s:\n", name);
    for (int i = 0; i < mat->rows; ++i)
    {
        for (int j = 0; j < mat->cols; ++j)
        {
            printf("%.2f ", matrix_get(mat, i, j));
        }
        printf("\n");
    }
}

void log_matrix(const Matrix *mat, const char *name)
{
    logger_info("%s:", name);
    for (int i = 0; i < mat->rows; ++i)
    {
        char row[256] = {0};
        int pos = 0;
        for (int j = 0; j < mat->cols; ++j)
        {
            pos += snprintf(row + pos, sizeof(row) - pos, "%.2f ", matrix_get(mat, i, j));
        }
        logger_info("%s", row);
    }
}

int main()
{
    // 初始化日志系统（日志级别为INFO）
    logger_init("app.log", LOG_INFO);
    logger_info("===== 程序启动 =====");
    printf("===== 程序启动 =====\n");

    // 测试矩阵功能
    logger_info("测试矩阵功能");
    printf("测试矩阵功能\n");
    Matrix *mat1 = matrix_create(2, 2);
    Matrix *mat2 = matrix_create(2, 2);

    // 设置矩阵值
    matrix_set(mat1, 0, 0, 1.0);
    matrix_set(mat1, 0, 1, 2.0);
    matrix_set(mat1, 1, 0, 3.0);
    matrix_set(mat1, 1, 1, 4.0);

    matrix_set(mat2, 0, 0, 5.0);
    matrix_set(mat2, 0, 1, 6.0);
    matrix_set(mat2, 1, 0, 7.0);
    matrix_set(mat2, 1, 1, 8.0);

    // 打印和记录矩阵
    log_matrix(mat1, "矩阵 mat1");
    log_matrix(mat2, "矩阵 mat2");

    // 矩阵加法
    Matrix *sum = matrix_add(mat1, mat2);
    log_matrix(sum, "矩阵加法结果");

    // 矩阵乘法
    Matrix *product = matrix_multiply(mat1, mat2);
    log_matrix(product, "矩阵乘法结果");

    // 测试几何功能
    logger_info("测试几何功能");
    Point p1 = point_create(0.0, 0.0);
    Point p2 = point_create(3.0, 4.0);

    logger_info("创建点 P1: (%.2f, %.2f)", p1.x, p1.y);
    logger_info("创建点 P2: (%.2f, %.2f)", p2.x, p2.y);

    double distance = point_distance(&p1, &p2);
    logger_info("两点之间的距离: %.2f", distance);

    // 创建线段
    Line line = line_create(&p1, &p2);
    double len = line_length(&line);
    logger_info("线段长度: %.2f", len);

    // 释放资源
    matrix_destroy(mat1);
    matrix_destroy(mat2);
    matrix_destroy(sum);
    matrix_destroy(product);

    logger_info("===== 程序结束 =====");

    logger_shutdown();

    return 0;
}

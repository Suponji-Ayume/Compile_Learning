#ifndef MATHX_ALGEBRA_MATRIX_H
#define MATHX_ALGEBRA_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 矩阵结构体 - 行优先存储
 */
typedef struct {
    int rows;       // 行数
    int cols;       // 列数
    double* data;   // 数据存储（一维数组）
} Matrix;

/**
 * 创建矩阵
 * @param rows 行数
 * @param cols 列数
 * @return 新创建的矩阵指针
 */
Matrix* matrix_create(int rows, int cols);

/**
 * 销毁矩阵并释放内存
 * @param mat 矩阵指针
 */
void matrix_destroy(Matrix* mat);

/**
 * 设置矩阵元素值
 * @param mat 矩阵指针
 * @param row 行索引（从0开始）
 * @param col 列索引（从0开始）
 * @param value 要设置的值
 */
void matrix_set(Matrix* mat, int row, int col, double value);

/**
 * 获取矩阵元素值
 * @param mat 矩阵指针
 * @param row 行索引
 * @param col 列索引
 * @return 元素值
 */
double matrix_get(const Matrix* mat, int row, int col);

/**
 * 矩阵加法
 * @param a 第一个矩阵
 * @param b 第二个矩阵
 * @return 结果矩阵
 */
Matrix* matrix_add(const Matrix* a, const Matrix* b);

/**
 * 矩阵乘法
 * @param a 第一个矩阵
 * @param b 第二个矩阵
 * @return 结果矩阵
 */
Matrix* matrix_multiply(const Matrix* a, const Matrix* b);

/**
 * 打印矩阵
 * @param mat 矩阵指针
 */
void matrix_print(const Matrix* mat);

#ifdef __cplusplus
}
#endif

#endif

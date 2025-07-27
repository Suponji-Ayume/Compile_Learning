#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

/**
 * 创建矩阵并初始化内存
 */
Matrix* matrix_create(int rows, int cols) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (!mat) return NULL;
    
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double*)calloc(rows * cols, sizeof(double));
    
    return mat;
}

/**
 * 销毁矩阵并释放内存
 */
void matrix_destroy(Matrix* mat) {
    if (mat) {
        free(mat->data);
        free(mat);
    }
}

/**
 * 设置矩阵元素值（行优先）
 */
void matrix_set(Matrix* mat, int row, int col, double value) {
    if (mat && row >= 0 && row < mat->rows && col >= 0 && col < mat->cols) {
        mat->data[row * mat->cols + col] = value;
    }
}

/**
 * 获取矩阵元素值
 */
double matrix_get(const Matrix* mat, int row, int col) {
    if (mat && row >= 0 && row < mat->rows && col >= 0 && col < mat->cols) {
        return mat->data[row * mat->cols + col];
    }
    return 0.0;
}

/**
 * 打印矩阵内容
 */
void matrix_print(const Matrix* mat) {
    if (!mat) return;
    
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%.2f\t", matrix_get(mat, i, j));
        }
        printf("\n");
    }
}

/**
 * 矩阵加法
 */
Matrix* matrix_add(const Matrix* a, const Matrix* b) {
    if (!a || !b || a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }
    
    Matrix* result = matrix_create(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            matrix_set(result, i, j, matrix_get(a, i, j) + matrix_get(b, i, j));
        }
    }
    
    return result;
}

/**
 * 矩阵乘法
 */
Matrix* matrix_multiply(const Matrix* a, const Matrix* b) {
    if (!a || !b || a->cols != b->rows) {
        return NULL;
    }
    
    Matrix* result = matrix_create(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < a->cols; k++) {
                sum += matrix_get(a, i, k) * matrix_get(b, k, j);
            }
            matrix_set(result, i, j, sum);
        }
    }
    
    return result;
}

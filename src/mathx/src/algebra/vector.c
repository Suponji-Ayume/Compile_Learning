#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

/**
 * 创建向量并初始化内存
 */
Vector* vector_create(int size) {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    if (!vec) return NULL;
    
    vec->size = size;
    vec->data = (double*)calloc(size, sizeof(double));
    
    return vec;
}

/**
 * 销毁向量并释放内存
 */
void vector_destroy(Vector* vec) {
    if (vec) {
        free(vec->data);
        free(vec);
    }
}

/**
 * 设置向量元素值
 */
void vector_set(Vector* vec, int index, double value) {
    if (vec && index >= 0 && index < vec->size) {
        vec->data[index] = value;
    }
}

/**
 * 获取向量元素值
 */
double vector_get(const Vector* vec, int index) {
    if (vec && index >= 0 && index < vec->size) {
        return vec->data[index];
    }
    return 0.0;
}

/**
 * 计算向量点积
 */
double vector_dot(const Vector* a, const Vector* b) {
    if (!a || !b || a->size != b->size) {
        return 0.0;
    }
    
    double result = 0.0;
    for (int i = 0; i < a->size; i++) {
        result += vector_get(a, i) * vector_get(b, i);
    }
    
    return result;
}

/**
 * 打印向量内容
 */
void vector_print(const Vector* vec) {
    if (!vec) return;
    
    printf("[");
    for (int i = 0; i < vec->size; i++) {
        printf("%.2f", vector_get(vec, i));
        if (i < vec->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

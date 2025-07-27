#ifndef MATHX_ALGEBRA_VECTOR_H
#define MATHX_ALGEBRA_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 向量结构体
 */
typedef struct {
    int size;       // 向量大小
    double* data;   // 数据存储
} Vector;

/**
 * 创建向量
 * @param size 向量大小
 * @return 新创建的向量指针
 */
Vector* vector_create(int size);

/**
 * 销毁向量并释放内存
 * @param vec 向量指针
 */
void vector_destroy(Vector* vec);

/**
 * 设置向量元素值
 * @param vec 向量指针
 * @param index 索引位置
 * @param value 要设置的值
 */
void vector_set(Vector* vec, int index, double value);

/**
 * 获取向量元素值
 * @param vec 向量指针
 * @param index 索引位置
 * @return 元素值
 */
double vector_get(const Vector* vec, int index);

/**
 * 向量点积
 * @param a 第一个向量
 * @param b 第二个向量
 * @return 点积结果
 */
double vector_dot(const Vector* a, const Vector* b);

/**
 * 打印向量
 * @param vec 向量指针
 */
void vector_print(const Vector* vec);

#ifdef __cplusplus
}
#endif

#endif

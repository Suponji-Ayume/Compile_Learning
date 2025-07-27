project(mathx C)

# 收集所有源文件
file(GLOB_RECURSE MATHX_SOURCES
    "src/algebra/*.c"
    "src/geometry/*.c"
)

# 创建静态库
add_library(mathx STATIC ${MATHX_SOURCES})

# 设置头文件路径
target_include_directories(mathx
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/mathx/algebra
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/mathx/geometry
)

# 链接数学库（用于sqrt等数学函数）
target_link_libraries(mathx m)

project(examples C)

# 添加可执行文件
add_executable(basic_usage basic_usage.c)

# 链接库
target_link_libraries(basic_usage
    PRIVATE
    mathx
    logger
)

# 针对所有 target
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

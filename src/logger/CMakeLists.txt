project(logger C)

# 收集所有源文件
file(GLOB_RECURSE LOGGER_SOURCES
    "src/*.c"
)

# 创建静态库
add_library(logger STATIC ${LOGGER_SOURCES})

# 设置头文件路径
target_include_directories(logger
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

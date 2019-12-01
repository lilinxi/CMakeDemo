SET(LIBHELLO_SRC hello.cpp)

ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)

# 改变静态库的名字
ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC})
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")

GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
MESSAGE(STATUS "This is the hello_static OUTPUT_NAME:" ${OUTPUT_VALUE})

# 定义 CLEAN_DIRECT_OUTPUT 属性
# cmake 在构建一个新的 target 时，会尝试清理掉其他使用这个名字的库。
SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 动态库版本号
# libhello.1.2.dylib
# libhello.1.dylib -> libhello.1.2.dylib
# libhello.dylib -> libhello.1.dylib
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

# 安装动态库
INSTALL(TARGETS hello hello_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

INSTALL(FILES hello.h DESTINATION include/hello)
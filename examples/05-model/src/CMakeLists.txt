ADD_EXECUTABLE(hello model.cpp)

# method 1
#INCLUDE_DIRECTORIES(/usr/include)
#TARGET_LINK_LIBRARIES(hello curl)
# end method 1

# method 2
# 对于系统预定义的 Find<name>.cmake 模块，使用方法一般如上例所示: 每一个模块都会定义以下几个变量
#   • <name>_FOUND
#   • <name>_INCLUDE_DIR or <name>_INCLUDES
#   • <name>_LIBRARY or <name>_LIBRARIES
FIND_PACKAGE(CURL)
IF (CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(hello ${CURL_LIBRARY})
ELSE (CURL_FOUND)
    MESSAGE(FATAL_ERROR ”CURL library not found”)
ENDIF (CURL_FOUND)
# end method 2

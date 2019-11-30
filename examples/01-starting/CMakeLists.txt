cmake_minimum_required(VERSION 3.14)
PROJECT(HELLO)

#  SET 指令可以用来显式的定义变量
SET(SRC_LIST starting.cpp)

# MESSAGE 指令用于向终端输出用户定义的信息，包含了三种类型:
#   1. SEND_ERROR，产生错误，生成过程被跳过。
#   2. SATUS，输出前缀为—的信息。
#   3. FATAL_ERROR，立即终止所有 cmake 过程。
# <projectname>_BINARY_DIR 以及 <projectname>_SOURCE_DIR
# 等同于：PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR
MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${HELLO_SOURCE_DIR})

ADD_EXECUTABLE(hello ${SRC_LIST})
MESSAGE(STATUS "This is the CMAKE_INCLUDE_PATH:" ${CMAKE_INCLUDE_PATH})
MESSAGE(STATUS "This is the CMAKE_LIBRARY_PATH:" ${CMAKE_LIBRARY_PATH})

# method 1
SET(CMAKE_INCLUDE_PATH /tmp/cmake/03-lib/usr/include/hello)
FIND_PATH(myHeader hello.h)
IF(myHeader)
    INCLUDE_DIRECTORIES(${myHeader})
ENDIF(myHeader)
# end method 1

# method 2
#INCLUDE_DIRECTORIES(/tmp/cmake/03-lib/usr/include/hello)
# end method 2

# TODO: !!!
# Error where ADD_EXECUTABLE is before LINK_DIRECTORIES or LINK_LIBRARIES
# ld: library not found for -lhello
# clang: error: linker command failed with exit code 1 (use -v to see invocation)

# method 1
LINK_DIRECTORIES(/tmp/cmake/03-lib/usr/lib)

ADD_EXECUTABLE(hello link.cpp)

TARGET_LINK_LIBRARIES(hello libhello.dylib)
# end method 1

# method 2
#LINK_LIBRARIES(/tmp/cmake/03-lib/usr/lib/libhello.dylib)
#
#ADD_EXECUTABLE(hello link.cpp)
#
#TARGET_LINK_LIBRARIES(hello)
# end method 2


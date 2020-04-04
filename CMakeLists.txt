cmake_minimum_required(VERSION 3.0.0)
project(ompeval VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 11)
find_package (Threads)

include(CTest)
enable_testing()

FILE(GLOB SRC_LIST_CPP ${PROJECT_SOURCE_DIR}/omp/*.cpp)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/omp/)

add_library(ompeval ${SRC_LIST_CPP})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

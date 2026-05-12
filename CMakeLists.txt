cmake_minimum_required(VERSION 3.14)
project(PointersWork14 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Вивід кольорових повідомлень
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(pointers_work14 main.cpp)

# Додаткові попередження
if(MSVC)
    target_compile_options(pointers_work14 PRIVATE /W4)
else()
    target_compile_options(pointers_work14 PRIVATE -Wall -Wextra -Wpedantic)
endif()

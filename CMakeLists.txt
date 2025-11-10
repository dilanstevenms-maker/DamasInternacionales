cmake_minimum_required(VERSION 3.22)
project(DamasChinas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (WIN32)
  set(CMAKE_PREFIX_PATH "C:/Qt/6.10.0/msvc2022_64" CACHE PATH "" FORCE)
endif()

find_package(Qt6 6.2 REQUIRED COMPONENTS Widgets)

add_executable(DamasChinas
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/boardview.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/boardview.h
)

target_link_libraries(DamasChinas PRIVATE Qt6::Widgets)

if (MSVC)
  target_compile_options(DamasChinas PRIVATE /utf-8)
endif()












cmake_minimum_required(VERSION 3.21)

project(game)

file(GLOB SOURCE src/main.c src/*.c)

add_executable(list "${SOURCE}")

# Set include directory search paths
target_include_directories(list
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

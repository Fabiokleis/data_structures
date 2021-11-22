cmake_minimum_required(VERSION 3.21)

project(snake)

file(GLOB SOURCE src/*.c)

add_executable(snake "${SOURCE}")

# Set include directory search paths
target_include_directories(snake
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

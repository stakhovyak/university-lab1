cmake_minimum_required(VERSION 3.25.1)

project(product-list)

# the source files
set(SOURCES
  main.cpp
  product.cpp
  list.cpp
  date.cpp
)

# the header files
set(HEADERS
  product.h
  list.h
  date.h
)

# the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# creating the executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})

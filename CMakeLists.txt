set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.8)
project(LCRS)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# Add source to this project's executable.
add_executable (LCRS "Main.cpp" "MainWindow.h" "MainWindow.cpp" "LCRS.hpp" "Node.h")

#fmt pkg
find_package(fmt CONFIG REQUIRED)
target_link_libraries(LCRS PRIVATE fmt::fmt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

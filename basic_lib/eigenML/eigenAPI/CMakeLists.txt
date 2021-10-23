cmake_minimum_required(VERSION 3.10)
project(HELLOGDB)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# for gdb debug
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(Eigen3_DIR "E:/gitProjects/ML_BASE/lib/eigen-3.4.0/build")

find_package(Eigen3 REQUIRED NO_MODULE)

add_executable(hello test.cc)

# link target file and lib file
target_link_libraries(hello Eigen3::Eigen) 
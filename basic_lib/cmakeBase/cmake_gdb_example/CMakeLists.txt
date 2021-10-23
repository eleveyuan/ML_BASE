cmake_minimum_required(VERSION 3.10)
project(HELLOGDB)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# for gdb debug
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

aux_source_directory(./ DIR_SRCS)

add_executable(hello  ${DIR_SRCS})
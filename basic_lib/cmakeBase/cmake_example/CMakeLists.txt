cmake_minimum_required(VERSION 3.10)
project(HELLO)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(./ DIR_SRCS)

add_executable(hello  ${DIR_SRCS})
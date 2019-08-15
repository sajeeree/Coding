cmake_minimum_required(VERSION 2.8.9)
project (embedded)
add_executable(embedded embedded.c)
target_link_libraries(embedded pthread)

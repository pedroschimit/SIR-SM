cmake_minimum_required(VERSION 3.16)
project(sir)

add_executable(sir sir.c random.c rede.c)

target_link_libraries(sir m)
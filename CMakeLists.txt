project(lsredis)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

aux_source_directory(src/ls/redis SRC)
aux_source_directory(sample SRC_SAMPLE)

include_directories(src)

add_library(lsredis SHARED ${SRC})
add_executable(testcase ${SRC} ${SRC_SAMPLE})

target_link_libraries(testcase hiredis lsnet lsconfig lsutil lsjson lsbuffer pthread lsorderedmap)

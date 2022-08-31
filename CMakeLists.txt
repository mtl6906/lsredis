project(lsredis)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

include_directories(include)

aux_source_directory(src/ls/redis SRC)
aux_source_directory(sample SRC_SAMPLE)

add_library(lsredis SHARED ${SRC})
add_executable(testcase ${SRC} ${SRC_SAMPLE})

target_link_libraries(testcase hiredis lslogger lsbuffer lsconfig lsjson lsbuffer lsfile lsexception lstime lsitem lscopyableitem lscstring lsio)

install(TARGETS lsredis DESTINATION lib)

install(DIRECTORY include/ls/redis DESTINATION include/ls)


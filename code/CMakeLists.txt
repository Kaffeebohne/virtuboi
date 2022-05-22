cmake_minimum_required(VERSION 3.20)

include_directories(src inc)

file(GLOB H_FILES **/*.hpp)
file(GLOB SRC_FILES **/*.cpp)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
#if CMAKE_BUILD_TYPE == Debug || CMAKE_BUILD_TYPE == RelWithDebInfo
add_definitions(-DDEBUGGING_ON=1)
#endif

add_executable(${PROJECT_NAME} ${H_FILES} ${SRC_FILES})

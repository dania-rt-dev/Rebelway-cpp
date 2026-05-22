cmake_minimum_required(VERSION 3.11)
project(school_app)
set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES src/user/user.cpp src/user/student.cpp src/user/teacher.cpp src/institution/institution.cpp main.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
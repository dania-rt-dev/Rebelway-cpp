cmake_minimum_required(VERSION 3.11)
project(gui_window)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(glfw3_DIR "C:/Users/Dania/GLFW/lib/cmake/glfw3")

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(third_party/imgui)

set(SOURCE_DIR
    main.cpp
    src/mainMenu.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE
    imgui
    imgui_stdlib
    imgui_glfw
    imgui_opengl3
    glfw
    OpenGL::GL
)
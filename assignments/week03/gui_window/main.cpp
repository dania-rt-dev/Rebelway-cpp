#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
#include "third_party/imgui/imgui.h"
#include <GLFW/glfw3.h>

#include "../include/mainMenu.hpp"

int main()
{
    int const WINDOW_WIDTH = 1200;
    int const WINDOW_HEIGHT = 720;
    MainMenu mainWindow = MainMenu(WINDOW_WIDTH, WINDOW_HEIGHT, "Window Test");
    mainWindow.createAndShowUI();

    return 0;
}
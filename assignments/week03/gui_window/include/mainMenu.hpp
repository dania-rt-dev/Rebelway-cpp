#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
#include <GLFW/glfw3.h>

class MainMenu
{
    private:
        int m_windowWidth{};
        int m_windowHeight{};
        std::string m_windowTitle;

        bool m_enable_menuMain{true};
        bool m_enable_menu01{false};
        bool m_enable_menu02{false};
        bool m_enable_menu03{false};
        float m_bgColor[3]{.0f, .0f, .0f};
        float m_bgOpacity{1.0f};
        float m_buttonSize = 50;

        int m_button01_SizeMult{100};
        int m_button02_SizeMult{100};
        int m_button03_SizeMult{100};

    public:
        /**
         * @brief Constructor for the class.
         *
         * @param windowWidth Window width.
         * @param windowHeight Window height.
         * @param windowTitle Window title.
         */
        MainMenu(int windowWidth, int windowHeight, std::string windowTitle);

        /**
         *  @brief Creates the functionality for the button 01.
         */
        void buttonPress_01();

        /**
         *  @brief Creates the functionality for the button 02.
         */
        void buttonPress_02();

        /**
         *  @brief Creates the functionality for the button 03.
         */
        void buttonPress_03();

        /**
         *  @brief Configures the Main menu display to be rendered;
         */
        void displayMenu_Main();

        /**
         *  @brief Configures the Menu01 display to be rendered;
         *
         *  This menu enables the fade of the background color.
         */
        void displayMenu_01();

        /**
         *  @brief Configures the Menu02 display to be rendered;
         *
         *  This menu allows you to pick the background color.
         */
        void displayMenu_02();

        /**
         *  @brief Configures the Menu03 display to be rendered;
         *
         *  This menu allows you to change the size of the lateral menu buttons.
         */
        void displayMenu_03();

        /**
         *  @brief Gather the window setup and renders it
         */
         void createAndShowUI();

};
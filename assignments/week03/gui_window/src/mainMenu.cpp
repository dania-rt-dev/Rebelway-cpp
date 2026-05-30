#include "../include/mainMenu.hpp"

bool doFade{false};
float elapsedTime{};

MainMenu::MainMenu
    (
        int windowWidth,
        int windowHeight,
        std::string windowTitle
    )
    :
    m_windowWidth(windowWidth),
    m_windowHeight(windowHeight),
    m_windowTitle(windowTitle)
{

}

void MainMenu::buttonPress_01()
{
    m_enable_menuMain = false;
    m_enable_menu01 = true;
    m_enable_menu02 = false;
    m_enable_menu03 = false;

    doFade = true;
}

void MainMenu::buttonPress_02()
{
    m_enable_menuMain = false;
    m_enable_menu01 = false;
    m_enable_menu02 = true;
    m_enable_menu03 = false;

    doFade = false;
}

void MainMenu::buttonPress_03()
{
    m_enable_menuMain = true;
    m_enable_menu01 = false;
    m_enable_menu02 = false;
    m_enable_menu03 = true;

    doFade = false;
}

void MainMenu::displayMenu_Main()
{
    ImGui::SetNextWindowPos(ImVec2(.0f, .0f), ImGuiCond_FirstUseEver);
    //ImGui::SetNextWindowSize(ImVec2(.0f, .0f), ImGuiCond_FirstUseEver);

    ImGui::Begin("Gui Test", nullptr,
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoTitleBar | 
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoBackground |
            ImGuiWindowFlags_AlwaysAutoResize
        );
        
        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(.0f, .0f, .0f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));

        if(ImGui::Button("Fade", ImVec2{m_buttonSize * (m_button01_SizeMult * .01f), m_buttonSize * (m_button01_SizeMult * .01f)}))
        {
            buttonPress_01();
        }
        if(ImGui::Button("Color\nPicker", ImVec2{m_buttonSize * (m_button02_SizeMult * .01f), m_buttonSize * (m_button02_SizeMult * .01f)}))
        {
            buttonPress_02();
        }
        if(ImGui::Button("Button\nsize", ImVec2{m_buttonSize * (m_button03_SizeMult * .01f), m_buttonSize * (m_button03_SizeMult * .01f)}))
        {
            buttonPress_03();
        }

        ImGui::PopStyleColor(2);
        ImGui::PopStyleVar(1);

        ImGui::End();
}

void MainMenu::displayMenu_01()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(.5f, .5f));
    ImGui::Begin("Back", nullptr,
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoTitleBar | 
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoBackground |
        ImGuiWindowFlags_AlwaysAutoResize
    );

    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(.0f, .0f, .0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    if(ImGui::Button("Back", ImVec2{m_buttonSize, m_buttonSize}))
    {
        m_enable_menu01 = false;
        doFade = false;
    }

    ImGui::PopStyleColor(2);
    ImGui::PopStyleVar(1);

    ImGui::End();
    
    if(!m_enable_menu01)
    {
        m_enable_menuMain = true;
    }
}

void MainMenu::displayMenu_02()
{
    ImGui::Begin("Color Picker", &m_enable_menu02,
        ImGuiWindowFlags_AlwaysAutoResize
    );
    ImGui::SliderFloat3("Color", m_bgColor, .0f, 1.0f);
    ImGui::ColorPicker3("Picker", m_bgColor);
    ImGui::End();
    
    if(!m_enable_menu02)
    {
        m_enable_menuMain = true;
    }
}

void MainMenu::displayMenu_03()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(.5f, .5f));
    ImGui::SetNextWindowSize(ImVec2(200.0f, 100.0f), ImGuiCond_FirstUseEver);
    ImGui::Begin("Button Size", &m_enable_menu03,
        ImGuiWindowFlags_AlwaysAutoResize
        );
    ImGui::SliderInt("Button 01 Size", &m_button01_SizeMult, 50, 200);
    ImGui::SliderInt("Button 02 Size", &m_button02_SizeMult, 50, 200);
    ImGui::SliderInt("Button 03 Size", &m_button03_SizeMult, 50, 200);

    ImGui::End();

    if(!m_enable_menu03)
    {
        m_enable_menuMain = true;
    }
}



void MainMenu::createAndShowUI()
{
    if(!glfwInit())
    {
        return;
    }

    GLFWwindow *window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // imGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if(m_enable_menuMain)
        {
            displayMenu_Main();
        }

        if(m_enable_menu01)
        {
            displayMenu_01();
        }

        if(m_enable_menu02)
        {
            displayMenu_02();
        }

        if(m_enable_menu03)
        {
            displayMenu_03();
        }

        if(doFade)
        {            
            float elapseTimer = 5.0f;

            if(elapsedTime < elapseTimer)
            {
                float delta = ImGui::GetIO().DeltaTime;
                elapsedTime += delta;
            }
            else
            {
                 elapsedTime = elapseTimer;
            }
            m_bgOpacity = 1.0f - (elapsedTime / elapseTimer);
        }
        else
        {
            elapsedTime = .0f;
            m_bgOpacity = 1.0f;
        }

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(m_bgColor[0] * m_bgOpacity, m_bgColor[1] * m_bgOpacity, m_bgColor[2] * m_bgOpacity, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    //cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}
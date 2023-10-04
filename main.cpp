#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLFW/glfw3.h> // Will drag system OpenGL headers

static void glfw_error_callback ( int error, const char* description )
{
    fprintf ( stderr, "GLFW Error %d: %s\n", error, description );
}

int main()
{
    glfwSetErrorCallback ( glfw_error_callback );
    if ( !glfwInit() )
        return 1;

    const char* glsl_version = "#version 130";
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 0 );

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow ( 1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr );
    if ( window == nullptr )
        return 1;
    glfwMakeContextCurrent ( window );
    glfwSwapInterval ( 1 ); // Enable vsync


    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL ( window, true );       // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    // * background color
    ImVec4 clear_color = ImVec4 ( 0.45f, 0.55f, 0.60f, 1.00f );

    while ( !glfwWindowShouldClose ( window ) )
    {
        // (Your code calls glfwPollEvents())
        glfwPollEvents();
        // * clear window
        glClearColor ( clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w );
        glClear ( GL_COLOR_BUFFER_BIT );

        // ...
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow(); // Show demo window! :)

        // Rendering
        // (Your code clears your framebuffer, renders your other stuff etc.)
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData ( ImGui::GetDrawData() );

        // (Your code calls glfwSwapBuffers() etc.)
        int display_w, display_h;
        glfwGetFramebufferSize ( window, &display_w, &display_h );
        glViewport ( 0, 0, display_w, display_h );
        glfwSwapBuffers ( window );
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow ( window );
    glfwTerminate();

    return 0;
}

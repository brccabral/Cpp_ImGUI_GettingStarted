# ImGUI getting started

This code is a mix of `Getting Started` article and `example_glfw_opengl3` main file.  
https://github.com/ocornut/imgui/wiki/Getting-Started#example-if-you-are-using-glfw--openglwebgl  
https://github.com/ocornut/imgui/tree/master/examples/example_glfw_opengl3  

- Clone the repo  
    - `git clone https://github.com/ocornut/imgui`
- Add to include path  
    - `path/to/imgui`
    - `path/to/imgui/backends`
- **Linux**
    - Install glfw3  
        - `sudo apt install libglfw3-dev`
    - Check glfw3 flags  
        - `pkg-config --static --libs glfw3`
        - `pkg-config --cflags glfw3`
- **Windows**
    - Download glfw3 binaries https://www.glfw.org/download
    - Define GLFW_DIR for cmake
    - Compile against `glfw3 opengl32` 
- Compile all these sources  
    - main.cpp
    - $(IMGUI_DIR)/imgui.cpp
    - $(IMGUI_DIR)/imgui_demo.cpp
    - $(IMGUI_DIR)/imgui_draw.cpp
    - $(IMGUI_DIR)/imgui_tables.cpp
    - $(IMGUI_DIR)/imgui_widgets.cpp
    - $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp
    - $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp

cmake_minimum_required(VERSION 3.21)
project(ImGUI_GettingStarted)

find_package(glfw3 REQUIRED)

if ("${IMGUI_DIR}" STREQUAL "")
    message(SEND_ERROR "define IMGUI_DIR")
    return()
endif()

message("IMGUI_DIR ${IMGUI_DIR}")

set(SOURCES "${IMGUI_DIR}/imgui.cpp;${IMGUI_DIR}/imgui_demo.cpp;${IMGUI_DIR}/imgui_draw.cpp;${IMGUI_DIR}/imgui_tables.cpp;${IMGUI_DIR}/imgui_widgets.cpp;${IMGUI_DIR}/backends/imgui_impl_glfw.cpp;${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${IMGUI_DIR};${IMGUI_DIR}/backends")
target_link_libraries(${PROJECT_NAME} glfw GL)
install(TARGETS ${PROJECT_NAME})
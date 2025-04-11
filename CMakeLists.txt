cmake_minimum_required(VERSION 3.28)

project(particelsSystem)

file( GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/source/*.cpp)


add_executable(particelsSystem ${SOURCE_FILES} ${LINK_DIRECTORIES})

# OpenGL
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
target_link_libraries(particelsSystem 
    OpenGL::GL
    GLEW
    glfw
)

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
void frame_call_back(GLFWwindow* window, int width,int height);
class Renderer{
    public:
        GLFWwindow *window;
        bool crashed=true;
        bool should_close=false;
        float* particels;
        unsigned int VB,VA;
    
    Renderer();
    void create_buffer(unsigned int & VA);
    void render_particels(float* particels,int number);
    void start_render();
    void end_render();

    ~Renderer();
};

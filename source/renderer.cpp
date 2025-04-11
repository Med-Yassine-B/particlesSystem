#include "renderer.hpp"
#include <cstdlib>

void frame_call_back(GLFWwindow* window, int width,int height){
    glViewport(0,0,width,height);
}
//======================================================
Renderer::Renderer(){
   srand(time(NULL)); 

    if(!glfwInit()){
        std::cerr<<"Failed to init glfw\n";
    }
    window=glfwCreateWindow(800, 600, "Particles System" , NULL,NULL);
    if(!window){
        std::cerr<<"Failes to initialize Window";
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frame_call_back);
     if(glewInit()!=GLEW_OK){
         std::cerr<<"failed to initialize\n";
     }
    Renderer::create_buffer(VA);
}
//======================================================
void Renderer::create_buffer(unsigned int & VA){
   glGenBuffers(1,&VA); 
   glBindBuffer(GL_ARRAY_BUFFER,VA);
}
//======================================================
void Renderer::render_particels(float* particels,int number){


    glBufferData(GL_ARRAY_BUFFER,number*6*sizeof(float),particels,GL_STATIC_DRAW);

    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0,6*number);
   // delete [] particels;
}
//======================================================
void Renderer::start_render(){
    glClearColor(0.1,0.1,0.2,1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(VA);

    Renderer::render_particels(particels, 50);

}
//======================================================

void Renderer::end_render(){

    glfwSwapBuffers(window);
    glfwPollEvents();
    should_close=glfwWindowShouldClose(window);
}
//======================================================

Renderer::~Renderer(){
    glfwDestroyWindow(window);
    glfwTerminate();
    delete [] particels;
    crashed=false;
}

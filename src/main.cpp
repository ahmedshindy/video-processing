#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

int main()
{
    GLFWwindow *window;
    if(!glfwInit())
    {
        std::cout<<"error\n";
        return 1; 
    }

    window = glfwCreateWindow(640,480,"Hello World",NULL,NULL);
    if(!window)
    {
        return -1;
    }

    unsigned char * data = new unsigned char [100 * 100 * 3];
    for( int y=0 ; y < 100 ; ++y){
        for(int x = 0 ; x < 100; ++x)
        {
            data[y*100 * 3 + x * 3     ] = 0xff; 
            data[y*100 * 3 + x * 3 + 1 ] = 0x00; 
            data[y*100 * 3 + x * 3  + 2] = 0x00; 
        }
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        glDrawPixels(100,100, GL_RGB,GL_UNSIGNED_BYTE ,data);
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }
    
    std::cout<<"hello"<<std::endl;

}
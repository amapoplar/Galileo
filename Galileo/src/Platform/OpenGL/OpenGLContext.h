#pragma once
#include "Galileo\Renderer\GraphicsContext.h"
#include<GLFW/glfw3.h>

struct GLFWWinow;


namespace Galileo{
    class OpenGLContext :
        public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow *windowHandle);
        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow* m_windowHandle;
    };
}


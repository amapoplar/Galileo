#include "glpch.h"
#include "OpenGLContext.h"
#include<glad/glad.h>
namespace Galileo {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_windowHandle(windowHandle)
	{
		GL_CORE_ASSERT(windowHandle, "Window handle is null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GL_CORE_ASSERT(status, "Failed to initialize GLAD!");
	}
	void OpenGLContext::SwapBuffers()
	{
		
		glfwSwapBuffers(m_windowHandle);
	}
}
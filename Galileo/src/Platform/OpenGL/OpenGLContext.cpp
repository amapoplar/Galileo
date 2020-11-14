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
		GL_CORE_INFO("OpenGL Infomation : ");
		GL_CORE_INFO("	Vendor:{0}", glGetString(GL_VENDOR));
		GL_CORE_INFO("	Renderer:{0}", glGetString(GL_RENDERER));
		GL_CORE_INFO("	Version:{0}", glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffers()
	{
		
		glfwSwapBuffers(m_windowHandle);
	}
}
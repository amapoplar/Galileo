#include"glpch.h"
#include "Application.h"

#include"Galileo/Core/Log.h"
#include<GLFW/glfw3.h>

namespace Galileo {
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)
}

Galileo::Application::Application()
{
	m_window = std::unique_ptr<Window>( Window::Create());
	m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

Galileo::Application::~Application()
{
}

void Galileo::Application::Run()
{
	WindowResizeEvent e(1200, 720);
	if (e.IsInCategory(EventCategoryApplication))
	{
		GL_TRACE(e);
	}
	if (e.IsInCategory(EventCategoryInput)) {
		GL_TRACE(e);
	}

	while (m_Running)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		m_window->OnUpdate();
	}
}

void Galileo::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	GL_CORE_TRACE("{0}",e);
}

bool Galileo::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

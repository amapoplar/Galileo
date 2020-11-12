#include"glpch.h"
#include "Application.h"
#include"Galileo/Core/Log.h"
#include<glad/glad.h>

namespace Galileo {
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)
	Application* Application::s_Instance = nullptr;
}

Galileo::Application::Application()
{
	GL_CORE_ASSERT(!s_Instance, "Application already exists!");
	s_Instance = this;
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
		for (Layer* layer:m_LayerStack)
		{
			layer->OnUpdate();
		}

		m_window->OnUpdate();
	}
}

void Galileo::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	GL_CORE_TRACE("{0}",e);

	for (auto it=m_LayerStack.end();it!=m_LayerStack.begin();)
	{
		(*--it)->OnEvent(e);
		if (e.Handled)
		{
			break;
		}
	}
}

void Galileo::Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void Galileo::Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
	layer->OnAttach();
}

bool Galileo::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

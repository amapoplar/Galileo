#include"glpch.h"
#include "Application.h"
#include"Galileo/Core/Log.h"
#include<glad/glad.h>
#include"Input.h"
#include<GLFW/glfw3.h>

namespace Galileo {
	Application* Application::s_Instance = nullptr;
}

Galileo::Application::Application()
{
	GL_CORE_ASSERT(!s_Instance, "Application already exists!");
	s_Instance = this;
	m_window = std::unique_ptr<Window>(Window::Create());
	m_window->SetEventCallback(GL_BIND_EVENT_FN(Application::OnEvent));
	m_ImGuiLayer = new ImGuiLayer();
	PushOverlay(m_ImGuiLayer);

	//Vertex Array
	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);

	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	VertexBuffer buffer = VertexBuffer::Creat(sizeof(vertices), vertices);
	buffer.Bind();

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	
	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

	unsigned int indices[] = { 0,1,2 };
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Shader
	const std::string vertexSrc = R"(
	#version 330 core
	layout(location = 0)
	in vec3 a_Position;
	out vec3 a_color;
	void main()
	{
		a_color = a_Position;
		gl_Position = vec4(a_Position,1.0);
	}
	
	)";
	const std::string fragmentSrc = R"(
	#version 330 core
	in vec3 a_color;
	out vec4 color; 
	
	void main()
	{
		color = vec4(a_color*0.5+0.5,0.8);
	}	

	)";
	m_Shader.reset(new Shader());
	m_Shader->Compile(vertexSrc.c_str(), fragmentSrc.c_str(), nullptr);

}

Galileo::Application::~Application()
{
}

void Galileo::Application::Run()
{
	
	WindowResizeEvent e(800, 720);
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

		m_Shader->Use();

		glBindVertexArray(m_VertexArray);
		glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,nullptr);

		for (Layer* layer:m_LayerStack)
		{
			layer->OnUpdate();
		}
		m_ImGuiLayer->Begin();
		for (Layer* layer : m_LayerStack)
		{
			layer->OnImGuiRender();
		}
		m_ImGuiLayer->End();
		m_window->OnUpdate();
	}
}

void Galileo::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(GL_BIND_EVENT_FN(Application::OnWindowClose));
	//GL_CORE_TRACE("{0}",e);
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

#pragma once
#include"Core.h"
#include"Galileo/Events/Event.h"
#include"Galileo/Events/ApplicationEvent.h"
#include"Window.h"
#include"Galileo/Core/Layer.h"
#include"Galileo/Core/LayerStack.h"

namespace Galileo {
	class GALILEO_API Application
	{
	public:
		Application();
		~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_window; }
	private:
		std::unique_ptr<Window> m_window;
		bool m_Running =true;
		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_LayerStack;
		static Application* s_Instance;
	
	};
	Application* CreateApplication();
}


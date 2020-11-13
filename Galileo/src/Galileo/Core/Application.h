#pragma once
#include"Core.h"
#include"Window.h"
#include"Galileo/Events/Event.h"
#include"Galileo/Events/ApplicationEvent.h"
#include"Galileo/Core/Layer.h"
#include"Galileo/Core/LayerStack.h"
#include"Galileo/ImGui/ImGuiLayer.h"

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
		//ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_window; }
	private:
		std::unique_ptr<Window> m_window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running =true;
		LayerStack m_LayerStack;
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		static Application* s_Instance;
	
	};
	Application* CreateApplication();
}


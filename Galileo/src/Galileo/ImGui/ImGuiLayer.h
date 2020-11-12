#pragma once
#include"Galileo/Core/Layer.h"

#include"Platform/OpenGL/imguiopengl.h"
#include"Galileo/Core/Application.h"
#include"Galileo/Events/KeyEvent.h"
#include"Galileo/Events/MouseEvent.h"


namespace Galileo {

	class GALILEO_API ImGuiLayer:public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach(); 
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMoveEvent(MouseMoveEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		
		bool OnKeyTypeEvent(KeyTypedEvent& event);
		bool OnWindowResizeEvent(WindowResizeEvent& event);

		float m_Time = 0.0f;
	};
}


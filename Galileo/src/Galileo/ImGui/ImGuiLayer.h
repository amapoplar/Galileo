#pragma once
#include"Galileo/Core/Layer.h"
namespace Galileo {

	class ImGuiLayer:public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach(); 
		void OnUpdate();
		void OnEvent(Event& event);
	private:
	};
}


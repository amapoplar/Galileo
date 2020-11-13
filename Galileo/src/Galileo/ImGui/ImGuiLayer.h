#pragma once
#include"Galileo/Core/Layer.h"

#include"Galileo/Events/KeyEvent.h"
#include"Galileo/Events/MouseEvent.h"


namespace Galileo {

	class GALILEO_API ImGuiLayer:public Layer
	{
	public:
		ImGuiLayer();

		virtual void OnAttach()override;
		virtual void OnDetach()override; 
		virtual void OnImGuiRender();
	
		void Begin();
		void End();

	private:

		float m_Time = 0.0f;
	};
}


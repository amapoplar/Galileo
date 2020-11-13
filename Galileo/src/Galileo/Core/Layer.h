#pragma once
#include"Galileo/Core/Core.h"
#include"Galileo/Events/Event.h"
namespace Galileo {
	class GALILEO_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		virtual void OnAttach(){}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName()const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};

}


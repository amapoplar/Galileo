#pragma once
#include"glpch.h"
#include"Galileo/Core/Core.h"
#include"Galileo/Events/Event.h"

namespace Galileo {
	struct  WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Galileo Engine",
			uint32_t width = 1960,
			uint32_t height = 1800)
			: Title(title), Width(width), Height(height)
		{
		}

	};
	class GALILEO_API Window{
	public:
		using EventCallbackFn = std::function<void(Event& )>;
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn & callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps & props = WindowProps());
	};
}


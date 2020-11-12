#pragma once
#include"Galileo/Core/Input.h"

namespace Galileo {

	class WindowsInput:public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode)override;
		virtual bool IsMouseButtonPressedImpl(int button)override;
		virtual float GetMouseXImpl()override;
		virtual float GetMouseYImpl()override;
		virtual std::pair<float, float> GetMousePostionImpl()override;
	};
}


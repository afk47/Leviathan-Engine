#pragma once
#include "REngine/Core/Input/Input.h"

namespace REngine {


	class WindowsInput : public Input 
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePosImpl() override;
	};


}

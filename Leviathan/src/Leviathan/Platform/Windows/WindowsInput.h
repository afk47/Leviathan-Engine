#pragma once
#include "Leviathan/Core/Input/Input.h"

namespace Leviathan {


	class WindowsInput : public Input 
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePosImpl() override;
		virtual void LockMouseImpl(bool lock) override;
	};


}

#pragma once

#include "Leviathan/Core/Core.h"

namespace Leviathan {

	class Input {
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float,float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
		inline static void LockMouse(bool lock) { s_Instance->LockMouseImpl(lock); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePosImpl() = 0;
		virtual void LockMouseImpl(bool lock) = 0;
	private:
		static Input* s_Instance;
	};
}
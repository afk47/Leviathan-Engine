#pragma once

#include "Leviathan/Core/Layer.h"
#include "Leviathan/Events/MouseEvent.h"
#include "Leviathan/Events/KeyEvent.h"
#include "Leviathan/Events/ApplicationEvent.h"

namespace Leviathan {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach()	override;
		virtual void OnDetach()	override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

		void SetDarkThemeColors();
	private:
		float m_Time = 0.0f;
	};
}
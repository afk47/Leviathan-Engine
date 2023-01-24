#pragma once

#include "REngine/Core/Layer.h"
#include "REngine/Events/MouseEvent.h"
#include "REngine/Events/KeyEvent.h"
#include "REngine/Events/ApplicationEvent.h"

namespace REngine {

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
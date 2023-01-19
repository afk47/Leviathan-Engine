#pragma once

#include "REngine/Core.h"
#include "Layer.h"

#include <vector>

namespace REngine {

	class RENGINE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		// Overlays are Layers that are always on top of the last regular layer
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};


}
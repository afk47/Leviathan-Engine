#pragma once

#include "Leviathan/Core/Core.h"
#include "Layer.h"

#include <vector>

namespace Leviathan {

	class LayerStack
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
		unsigned int m_LayerInsertIndex = 0;
	};


}
#pragma once

namespace Leviathan {

	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	private:
			
	};

}
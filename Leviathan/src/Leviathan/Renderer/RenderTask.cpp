#include "lpch.h"
#include "RenderTask.h"

namespace Leviathan {

	Unique<RendererAPI> RenderTask::s_RendererAPI = RendererAPI::Create();
}
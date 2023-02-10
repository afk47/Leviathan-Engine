#include "repch.h"
#include "RenderTask.h"

namespace REngine {

	Unique<RendererAPI> RenderTask::s_RendererAPI = RendererAPI::Create();
}
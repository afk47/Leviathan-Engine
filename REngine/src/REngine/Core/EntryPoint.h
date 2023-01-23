#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern REngine::Application* REngine::CreateApplication();

int main(int argc, char** argv) {
	REngine::Log::Init();
	RE_CORE_WARN("Initialized Log!");
	int a = 5;
	RE_INFO("Initialized Log! Var={0}", a);

	auto app = REngine::CreateApplication();
	app->Run();
	delete app;
}
#endif

#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern Leviathan::Application* Leviathan::CreateApplication();

int main(int argc, char** argv) {
	Leviathan::Log::Init();
	RE_CORE_WARN("Initialized Log!");
	int a = 5;
	RE_INFO("Initialized Log! Var={0}", a);

	auto app = Leviathan::CreateApplication();
	app->Run();
	delete app;
}
#endif

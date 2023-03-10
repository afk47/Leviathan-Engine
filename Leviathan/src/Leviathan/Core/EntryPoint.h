#pragma once

#ifdef LE_PLATFORM_WINDOWS

extern Leviathan::Application* Leviathan::CreateApplication();

int main(int argc, char** argv) {
	Leviathan::Log::Init();

	LE_PROFILE_BEGIN_SESSION("Startup","Leviathan-Profile-Startup.json");
	auto app = Leviathan::CreateApplication();
	LE_PROFILE_END_SESSION();

	LE_PROFILE_BEGIN_SESSION("Runtime", "Leviathan-Profile-Runtime.json");
	app->Run();
	LE_PROFILE_END_SESSION();
	
	LE_PROFILE_BEGIN_SESSION("Shutdown", "Leviathan-Profile-Shutdown.json");
	delete app;
	LE_PROFILE_END_SESSION();
}
#endif

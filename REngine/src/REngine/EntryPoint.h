#pragma once

#ifdef RE_PLATFORM_WINDOWS

extern RE::Application* RE::CreateApplication();

int main(int argc, char** argv) {

	auto app = RE::CreateApplication();
	app->Run();
	delete app;
}
#endif

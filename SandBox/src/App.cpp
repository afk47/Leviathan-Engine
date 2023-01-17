#include <REngine.h>

class Sandbox : public REngine::Application {

public:
	Sandbox() {

	}
	~Sandbox() {

	}
};


REngine::Application* REngine::CreateApplication(){
	return new Sandbox();
}
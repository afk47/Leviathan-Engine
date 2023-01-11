#include <REngine.h>

class Sandbox : public RE::Application {

public:
	Sandbox() {

	}
	~Sandbox() {

	}
};


RE::Application* RE::CreateApplication(){
	return new Sandbox();
}
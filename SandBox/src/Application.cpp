#include<Galileo.h>

class Sandbox:public Galileo::Application
{
public:
	Sandbox();
	~Sandbox();

private:

};

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

Galileo::Application* Galileo::CreateApplication() {
	return new Sandbox;
}
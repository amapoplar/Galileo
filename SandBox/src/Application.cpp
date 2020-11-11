#include<Galileo.h>
class ExampleLayer:public Galileo::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {
	};
	void OnUpdate() override {
		GL_INFO("ExampleLayer::Update");
	}
	void OnEvent(Galileo::Event& event) override {
		GL_INFO("{0}",event);
	}
private:

};

class Sandbox:public Galileo::Application
{
public:
	Sandbox();
	~Sandbox();

private:

};

Sandbox::Sandbox()
{
	PushLayer(new ExampleLayer());
}

Sandbox::~Sandbox()
{
}

Galileo::Application* Galileo::CreateApplication() {
	return new Sandbox;
}
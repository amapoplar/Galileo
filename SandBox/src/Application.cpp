#include<Galileo.h>

class ExampleLayer:public Galileo::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {
	};
	void OnUpdate() override {
	}
	void OnEvent(Galileo::Event& event) override {
		//GL_INFO("{0}",event);
		if (event.GetEventType()==Galileo::EventType::KeyPressed)
		{
			Galileo::KeyPressedEvent& e = (Galileo::KeyPressedEvent&)event;
			GL_TRACE("{0}", (char)e.GetKeyCode());
		}
		if (Galileo::Input::IsKeyPressed(GL_KEY_TAB))
		{
			GL_INFO("The window size is {0},{1}", Galileo::Application::Get().GetWindow().GetWidth(),
				Galileo::Application::Get().GetWindow().GetHeight());
		}
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
	PushLayer(new Galileo::ImGuiLayer());
}

Sandbox::~Sandbox()
{
}

Galileo::Application* Galileo::CreateApplication() {
	return new Sandbox;
}
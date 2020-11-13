#include<Galileo.h>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include<imgui/imgui.h>
glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

class ExampleLayer:public Galileo::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {
	};

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
	//PushLayer(new Galileo::ImGuiLayer());
}

Sandbox::~Sandbox()
{
}

Galileo::Application* Galileo::CreateApplication() {
	return new Sandbox;
}
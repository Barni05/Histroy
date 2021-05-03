#include "hspch.h"
#include "Triangle.h"
Triangle::Triangle()
{
	std::pair<float, float> positions[3];
	positions[0] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2, Histroy::Application::mWindowHeight / 2 / 2);
	positions[1] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2 + Histroy::Application::mWindowWidth/2, Histroy::Application::mWindowHeight / 2 / 2);
	positions[2] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2, Histroy::Application::mWindowHeight / 2 / 2 + Histroy::Application::mWindowHeight / 2);
	mInitialPosition[0] = positions[0].first;
	mInitialPosition[1] = positions[0].second;
	mInitialPosition[2] = positions[1].first;
	mInitialPosition[3] = positions[1].second;
	mInitialPosition[4] = positions[2].first;
	mInitialPosition[5] = positions[2].second;
	mProj = glm::ortho(0.0f, float(Histroy::Application::mWindowWidth), 0.0f, float(Histroy::Application::mWindowHeight), -1.0f, 1.0f);
	mView = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,0));
	mModel = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	mMVP = mModel * mView * mProj;
	mColor[0] = 1.0f;
	mColor[1] = 1.0f;
	mColor[2] = 0.0f;
	mColor[3] = 1.0f;
}

Triangle::Triangle(float color[4])
{
	std::pair<float, float> positions[3];
	positions[0] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2, Histroy::Application::mWindowHeight / 2 / 2);
	positions[1] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2 + Histroy::Application::mWindowWidth / 2, Histroy::Application::mWindowHeight / 2 / 2);
	positions[2] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2, Histroy::Application::mWindowHeight / 2 / 2 + Histroy::Application::mWindowHeight / 2);
	mInitialPosition[0] = positions[0].first;
	mInitialPosition[1] = positions[0].second;
	mInitialPosition[2] = positions[1].first;
	mInitialPosition[3] = positions[1].second;
	mInitialPosition[4] = positions[2].first;
	mInitialPosition[5] = positions[2].second;

	UpdateTransform();
	for (int i = 0; i < 4; i++)
	{
		mColor[i] = color[i];
	}
}

void Triangle::Render()
{
	VertexBuffer vb(6 * sizeof(float), mInitialPosition);
	vb.Bind();
	unsigned int indicies[] = { 0,1,2};
	IndexBuffer ib(3, indicies);
	ib.Bind();
	VertexBufferLayout layout;
	layout.PushLayout<float>(2, false);

	VertexArray va;
	va.Bind();
	va.AddBuffer(vb, layout);

	Shader shader("src/Engine/GUI/Shaders/Geometry.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", mColor[0], mColor[1], mColor[2], mColor[3]);
	UpdateTransform();
	shader.SetUniformMat4("u_MVP", mMVP);
	Renderer renderer;
	renderer.DrawElements(shader, va, ib);
}

void Triangle::ImGuiRender()
{
	ImGui::SliderFloat3("Location", &mLocation.x, -1.0f, 1.0f);

}

void Triangle::UpdateTransform()
{
	mProj = glm::ortho(0.0f, float(Histroy::Application::mWindowWidth), 0.0f, float(Histroy::Application::mWindowHeight), -1.0f, 1.0f);
	mView = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	mModel = glm::translate(glm::mat4(1.0f), mLocation);
	mMVP = mModel * mView * mProj;
}
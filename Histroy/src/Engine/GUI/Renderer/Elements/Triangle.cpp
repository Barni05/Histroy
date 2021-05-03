#include "hspch.h"
#include "Triangle.h"
Triangle::Triangle()
{
	std::pair<float, float> positions[3];
	positions[0] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2, Histroy::Application::mWindowHeight / 2 / 2);
	positions[1] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2 + Histroy::Application::mWindowWidth/2, Histroy::Application::mWindowHeight / 2 / 2);
	positions[2] = std::make_pair<float, float>(0, Histroy::Application::mWindowHeight / 2 / 2 + Histroy::Application::mWindowHeight / 2);
	mInitialPosition[0] = positions[0].first;
	mInitialPosition[1] = positions[0].second;
	mInitialPosition[2] = positions[1].first;
	mInitialPosition[3] = positions[1].second;
	mInitialPosition[4] = positions[2].first;
	mInitialPosition[5] = positions[2].second;
	mProj = glm::ortho(0.0f, float(Histroy::Application::mWindowWidth), 0.0f, float(Histroy::Application::mWindowHeight), -1.0f, 1.0f);
	mView = glm::translate(glm::mat4(1.0f), glm::vec3(-100,0,0));
	mModel = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));
	mMVP = mModel * mView * mProj;
}

void Triangle::Render()
{
	float pos[] = {350.0f, 225.0f, 1050.0f, 225.0f, 700.0f, 675.0f};
	VertexBuffer vb(6 * sizeof(float), pos);
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
	shader.SetUniform4f("u_Color", 1.0f, 1.0f, 0.0f, 1.0f);
	glm::mat4 proj = glm::ortho(0.0f, 1400.0f, 0.0f, 900.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	glm::mat4 mvp = proj * view * model;
	std::cout << glm::to_string(mvp) << std::endl;
	shader.SetUniformMat4("u_MVP", mvp);
	Renderer renderer;
	renderer.DrawElements(shader, va, ib);/*
	float data[] = { -0.5f, -0.5f,
	0.5f, -0.5f,
		0.0f, 0.5f
	};
	VertexBuffer vb(6 * sizeof(float), data);
	unsigned int indicies[] = { 0,1,2 };
	IndexBuffer ib(3, indicies);
	ib.Bind();
	VertexBufferLayout layout;
	layout.PushLayout<float>(2, false);

	VertexArray va;
	va.AddBuffer(vb, layout);

	Shader shader("src/Engine/GUI/Shaders/Geometry.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 1.0f, 1.0f, 0.0f, 1.0f);
	shader.SetUniformMat4("u_MVP", glm::mat4(1.0f));
	Renderer renderer;
	renderer.DrawElements(shader, va, ib);*/
}
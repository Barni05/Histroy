#include "hspch.h"
#include "Square.h"

Square::Square()
{
	Init();
	UpdateTransform();
	mColor[0] = 1.0f;
	mColor[1] = 1.0f;
	mColor[2] = 1.0f;
	mColor[3] = 1.0f;
}

Square::~Square()
{
}

void Square::Init()
{
	mName = "Square";
	mBufferID = new char[256];
	mBufferID = (char*)mID.c_str();
	std::pair<float, float> positions[4];
	positions[0] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2, Histroy::Application::mWindowHeight / 2 / 2);
	positions[1] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2 + Histroy::Application::mWindowWidth / 2, Histroy::Application::mWindowHeight / 2 / 2);
	positions[2] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2 + Histroy::Application::mWindowWidth / 2, Histroy::Application::mWindowHeight / 2 / 2 + Histroy::Application::mWindowHeight / 2);
	positions[3] = std::make_pair<float, float>(Histroy::Application::mWindowWidth / 2 / 2, Histroy::Application::mWindowHeight / 2 / 2 + Histroy::Application::mWindowHeight / 2);
	bool bFirst = true;
	int pairInd = 0;
	for (int i = 0; i < 8; i++)
	{
		mInitialPositions[i] = bFirst ? positions[pairInd].first : positions[pairInd].second;
		pairInd = bFirst ? pairInd : pairInd + 1;
		bFirst = bFirst ? false : true;
	}
	mLocation = glm::vec3(0);
	std::stringstream ss;
	ss << mName << "_" << Triangle::sGeometryNumber;
	mID = ss.str();
}

void Square::Render()
{
	unsigned int indicies[]{ 0,1,2,0,2,3 };
	VertexBuffer vb(8 * sizeof(float), mInitialPositions);
	vb.Bind();

	IndexBuffer ib(6, indicies);
	ib.Bind();

	VertexBufferLayout layout;
	layout.PushLayout<float>(2, false);

	VertexArray va;
	va.AddBuffer(vb, layout);
	va.Bind();

	Shader shader("src/Engine/GUI/Shaders/Geometry.shader");
	shader.Bind();

	shader.SetUniform4f("u_Color", mColor[0], mColor[1], mColor[2], mColor[3]);
	UpdateTransform();
	shader.SetUniformMat4("u_MVP", mMVP);
	Renderer renderer;
	renderer.DrawElements(shader, va, ib);
}

void Square::UpdateTransform()
{
	mProj = glm::ortho(0.0f, float(Histroy::Application::mWindowWidth), 0.0f, float(Histroy::Application::mWindowHeight), -1.0f, 1.0f);
	mView = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	mModel = glm::translate(glm::mat4(1.0f), mLocation);
	mMVP = mProj * mView * mModel;
}

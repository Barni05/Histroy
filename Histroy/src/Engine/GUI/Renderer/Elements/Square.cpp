#include "hspch.h"
#include "Square.h"
namespace Histroy
{
	Square::Square() :Geometry()
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
		positions[0] = std::make_pair<float, float>(Histroy::Application::mEditorDetails.viewportWidth / 2 / 2, Histroy::Application::mEditorDetails.viewportHeight / 2 / 2);
		positions[1] = std::make_pair<float, float>(Histroy::Application::mEditorDetails.viewportWidth / 2 / 2 + Histroy::Application::mEditorDetails.viewportWidth / 2, Histroy::Application::mEditorDetails.viewportHeight / 2 / 2);
		positions[2] = std::make_pair<float, float>(Histroy::Application::mEditorDetails.viewportWidth / 2 / 2 + Histroy::Application::mEditorDetails.viewportWidth / 2, Histroy::Application::mEditorDetails.viewportHeight / 2 / 2 + Histroy::Application::mEditorDetails.viewportHeight / 2);
		positions[3] = std::make_pair<float, float>(Histroy::Application::mEditorDetails.viewportWidth / 2 / 2, Histroy::Application::mEditorDetails.viewportHeight / 2 / 2 + Histroy::Application::mEditorDetails.viewportHeight / 2);
		bool bFirst = true;
		int pairInd = 0;
		for (int i = 0; i < 8; i++)
		{
			mInitialPositions[i] = bFirst ? positions[pairInd].first : positions[pairInd].second;
			pairInd = bFirst ? pairInd : pairInd + 1;
			bFirst = bFirst ? false : true;
		}
		mLocation = glm::vec3(0, 0, 0);
		mScale = glm::vec3(1.f);
		std::stringstream ss;
		mGeometryNumber = AssignIdNumber();
		ss << mName << "_" << mGeometryNumber;
		mID = ss.str();
		mProj = glm::ortho(0.0f, float(Histroy::Application::mEditorDetails.viewportWidth), 0.0f, float(Histroy::Application::mEditorDetails.viewportHeight), -1.0f, 1.0f);
	}

	void Square::Render()
	{
		VertexBuffer vb(8 * sizeof(float), mInitialPositions);
		vb.Bind();
		unsigned int indicies[] = { 0,1,2,0,2,3 };
		IndexBuffer ib(6, indicies);
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

	void Square::ImGuiRender()
	{
		ImGui::Begin("Properties");
		ImGui::InputText("Name", mBufferID, 256);
		mID = std::string(mBufferID);
		ImGui::SliderFloat2("Location", &mLocation.x, -float(Histroy::Application::mEditorDetails.height), float(Histroy::Application::mEditorDetails.width));
		ImGui::InputFloat2("Scale", &mScale.x);
		ImGui::SliderAngle("Rotation", &mRotation);
		ImGui::ColorEdit4("Color", mColor);
		ImGui::End();

		mCodeHandler->RenderImGui();
	}
}
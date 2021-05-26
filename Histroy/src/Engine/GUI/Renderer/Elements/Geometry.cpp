#include "hspch.h"
#include "Geometry.h"

namespace Histroy
{
	bool Geometry::IsObjectPressed(int x, int y, float color[4])
	{
		glFlush();
		glFinish();
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		struct { GLubyte red, green, blue; } pixel;
		glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel);
		float clickedColor[3];
		clickedColor[0] = (float)((float)pixel.red / 255);
		clickedColor[1] = (float)((float)pixel.green / 255);
		clickedColor[2] = (float)((float)pixel.blue / 255);
		if ((clickedColor[0] == color[0] || abs(clickedColor[0] - color[0]) < 0.01f) && (clickedColor[1] == color[1] || abs(clickedColor[1] - color[1]) < 0.01f) && (clickedColor[2] == color[2] || abs(clickedColor[2] - color[2]) < 0.01f))
		{
			return true;
		}
		return false;
	}

	Geometry::Geometry() :mName("Geometry")
	{
		mCodeHandler = std::make_shared<Histroy::CodeHandler>();
		mCodeHandler->Init(this);
	}

	Geometry::~Geometry()
	{
	}

	void Geometry::UpdateTransform()
	{
		mView = glm::translate(glm::mat4(1.0f), glm::vec3(0.f));
		mModel = glm::translate(glm::mat4(1.0f), mLocation);
		mModel = glm::rotate(mModel, mRotation, glm::vec3(0.0f, 0.f, 1.f));
		mModel = glm::scale(mModel, mScale);
		mMVP = mProj * mView * mModel;
	}

	void Geometry::OnMouseButtonPressed(Histroy::Event& e)
	{
		Histroy::MouseButtonPressed* event = dynamic_cast<Histroy::MouseButtonPressed*>(&e);
		if (IsObjectPressed(event->GetXpos(), event->GetYpos(), mColor))
		{
			Histroy::Application::sSelectedObject = this;
		}
	}

    void Geometry::EventHappened(Event& e)
    {
		mCodeHandler->EventHappened(e);
    }

	int Geometry::AssignIdNumber()
	{
		if (Histroy::HistroyRenderer::sGeometries.size() != 0)
		{
			std::vector<int> IDs;
			for (auto geometries : Histroy::HistroyRenderer::sGeometries)
			{
				if (geometries->GetName() == this->GetName())
				{
					IDs.push_back(geometries->GetGeometryNumber());
				}
			}
			if (IDs.size() > 0)
			{
				int max = IDs[0];
				for (int id : IDs)
				{
					if (id > max)
					{
						max = id;
					}
				}
				return max + 1;
			}
		}
		return 1;
	}
}
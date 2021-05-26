#include "hspch.h"
#include "Program.h"
namespace Histroy
{
	void Program::BeginPlay(Event& e)
	{
		for (auto actor : mActors)
		{
			actor->EventHappened(e);
		}
	}

	void Program::Tick(Event& e)
	{
	}

	void Program::KeyPressed(Event& e)
	{
	}

	void Program::KeyReleased(Event& e)
	{
	}

	void Program::MouseButtonPressed(Event& e)
	{
	}

	void Program::MouseButtonReleased(Event& e)
	{
	}
}
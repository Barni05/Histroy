#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <thread>
#include "SGL.h"

#include "Application/Application.h"

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

#include "Engine/Events/Event.h"
#include "Engine/Events/KeyEvents.h"
#include "Engine/Events/WindowEvents.h"
#include "Engine/Events/MouseEvents.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Engine/GUI/imgui/HistroyGui.h"
#include "Engine/GUI/Menus/Menus.h"
#include "Engine/GUI/Renderer/Elements/Triangle.h"
#include "Engine/GUI/Renderer/HistroyRenderer.h"
#include "Engine/GUI/Renderer/Elements/Geometry.h"
#include "Engine/GUI/Renderer/Elements/Square.h"
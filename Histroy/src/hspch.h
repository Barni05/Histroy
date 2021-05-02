#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <thread>

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

#include "Engine/Events/Event.h"
#include "Engine/Events/KeyEvents.h"
#include "Engine/Events/WindowEvents.h"
#include "Engine/Events/MouseEvents.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

#include "SGL.h"

#include "Engine/GUI/imgui/HistroyGui.h"
#include "Engine/GUI/Menus/Menus.h"
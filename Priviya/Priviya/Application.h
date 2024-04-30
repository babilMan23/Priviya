#pragma once

#include "Core.h"
#include "util/Debug.h"
#include "windowing/Window.h"
#include "gui/GUI.h"
#include "renderer/entities/Model.h"
#include "shaders/Shader.h"
#include "renderer/tools/EntityRenderer.h"
#include "renderer/elements/FBO.h"

namespace Priviya {
	class Application {
	public:
		Application() = default;

		PV_API PVResult run();
	};
}
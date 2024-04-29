#pragma once

#include "Core.h"
#include "util/Debug.h"
#include "windowing/Window.h"
#include "gui/GUI.h"
#include "renderer/entities/Model.h"

namespace Priviya {
	class Application {
	public:
		Application() = default;

		PV_API PVResult run();
	};
}
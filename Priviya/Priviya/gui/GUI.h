#pragma once

#include "../Core.h"
#include "../renderer/elements/FBO.h"
#include "../Vendor/imgui/imgui.h"
#include "../Vendor/imgui/imgui_impl_glfw.h"
#include "../Vendor/imgui/imgui_impl_opengl3_loader.h"
#include "../Vendor/imgui/imgui_internal.h"
#include "../Vendor/imgui/imgui_impl_opengl3.h"
#include "../Vendor/imgui/imconfig.h"
#include "../util/Debug.h"

namespace Priviya {
	struct GUIButton {
		inline static bool create(const string& title, int width, int height);
	};

	class GUIManager {
	public:
		void init(GLFWwindow* window);
		void destroy();

		void update(FBO* fbo, int w, int h);
	};
}
#pragma once

#include "../Core.h"
#include "../renderer/GL.h"
#include "WindowCallbacks.h"

#include <GLFW/glfw3.h>

namespace Priviya {
	class Window {
	public:

		Window() = default;
		~Window() = default;

		bool create(int width, int height, const std::string& title, bool debugContext);
		void update();
		void swapBuffers();
		void destroy();

		GLFWwindow* getWindow() {
			return _window;
		}

	private:
		GLFWwindow* _window;
		int _width, _height;
		std::string _title;
	};
}
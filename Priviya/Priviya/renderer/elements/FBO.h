#pragma once

#include "../../Core.h"
#include "../../util/Debug.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Priviya {
	class FBO {
	public:
		FBO() = default;
		~FBO() = default;
		FBO(int width, int height, GLFWwindow* window);

		void ResizeFBO(int width, int height);
		void bind();
		void unbind();
		void destroy();

		uint getFrameTexture();
	private:
		uint id;
		uint tex;
		uint rbo;
	};
}
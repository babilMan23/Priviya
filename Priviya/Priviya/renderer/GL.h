#pragma once

#include "../Core.h"
#include "../util/Debug.h"
#include "entities/Model.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Priviya {
	class GL {
	public:
		GL() = default;
		~GL() = default;
	
		void prepare();
		void render(Model model);

		static bool create(bool debugContext);
		static PV_REF<Priviya::GL> getGL();
	private:
		static void APIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
			GLenum severity, GLsizei length,
			const GLchar* msg, const void* data);
	};
}
#pragma once

#include "../entities/Model.h"
#include "../../shaders/Shader.h"
#include "../GL.h"
#include "../elements/FBO.h"

namespace Priviya {
	class EntityRenderer {
	public:
		void render(Model mode, DefaultShader shader, FBO fbo);
	};
}

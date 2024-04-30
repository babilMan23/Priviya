#include "EntityRenderer.h"

void Priviya::EntityRenderer::render(Model model, DefaultShader shader, FBO fbo) {
	GL::getGL()->prepare();
	shader.use();
	fbo.bind();
	GL::getGL()->prepareFBO();
	GL::getGL()->render(model);
	fbo.unbind();
	shader.disable();
}

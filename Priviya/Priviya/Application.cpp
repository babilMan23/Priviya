#include "Application.h"

namespace Priviya {
	PV_API PVResult Application::run() {
		Logger::Init();
		PV_INFO("Welcome To Priviya 2024.4");

		bool debug = false;

		#ifdef PV_DEBUG
			debug = true;
		#endif

		Window window;
		if (!window.create(1920, 1080, "Priviya Engine", debug)) {return -1;}

		initializeCallbacks();
		URV urv;

		GUIManager gui;
		gui.init(window.getWindow());

		Model model;
		model.create();

		DefaultShader shader;
		shader.generate();

		EntityRenderer renderer;

		int scrw, scrh;
		glfwGetFramebufferSize(window.getWindow(), &scrw, &scrh);

		FBO framebuf(scrw, scrh, window.getWindow());

		glfwShowWindow(window.getWindow());

		while (!glfwWindowShouldClose(window.getWindow())) {
			window.update();

			updateCallbacks(window.getWindow(), &urv);

			renderer.render(model, shader, framebuf);

			int scrw, scrh;
			glfwGetFramebufferSize(window.getWindow(), &scrw, &scrh);

			gui.update(&framebuf, scrw, scrh);

			window.swapBuffers();
		}

		framebuf.destroy();
		gui.destroy();
		shader.destroy();
		window.destroy();
		return 0;
	}
}
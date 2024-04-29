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

		std::vector<float> vertices = {
			// Position (x, y, z)
			-0.5f,  0.5f, 0.0f,   // Top left
			0.5f,  0.5f, 0.0f,   // Top right
			0.5f, -0.5f, 0.0f,   // Bottom right
			-0.5f, -0.5f, 0.0f    // Bottom left
		};

		std::vector<uint> indices = {
			0, 1, 2,   // First triangle (top right, top left, bottom right)
			2, 3, 0    // Second triangle (bottom right, bottom left, top left)
		};

		Model model;
		model.create(vertices, indices);

		glfwShowWindow(window.getWindow());

		while (!glfwWindowShouldClose(window.getWindow())) {
			window.update();

			GL::getGL()->prepare();

			updateCallbacks(window.getWindow(), &urv);

			GL::getGL()->render(model);

			gui.update();

			window.swapBuffers();
		}

		gui.destroy();
		window.destroy();
		return 0;
	}
}
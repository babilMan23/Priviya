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

		glfwShowWindow(window.getWindow());

		while (!glfwWindowShouldClose(window.getWindow())) {
			window.update();

			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(1, 1, 0, 1);

			gui.update();

			updateCallbacks(window.getWindow(), &urv);

			window.swapBuffers();
		}

		gui.destroy();
		window.destroy();
		return 0;
	}
}
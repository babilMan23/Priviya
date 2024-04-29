#include "Window.h"

bool Priviya::Window::create(int width, int height, const std::string& title, bool debugContext) {
	if (!glfwInit()) {
		PV_CRITICAL("Failed to initialize GLFW!");
		std::cin.get();
		return false;
	}

	if (debugContext) {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	} else {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	}

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

	_width = width;
	_height = height;
	_title = title;

	_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

	if (_window == nullptr) {
		PV_ERROR("Failed to create GLFW window!");
		return false;
	}

	glfwMakeContextCurrent(_window);
	GL::create(debugContext);
	
	glfwSetFramebufferSizeCallback(_window, Priviya::framebuffer_size_callback);
	glfwSetKeyCallback(_window, Priviya::key_callback);

	PV_INFO("Create Priviya Window With ID : {}", (long) _window);
	return true;
}

void Priviya::Window::update() {
	glfwPollEvents();
}

void Priviya::Window::swapBuffers() {
	glfwSwapBuffers(_window);
}

void Priviya::Window::destroy() {
	glfwDestroyWindow(_window);
	glfwTerminate();
}

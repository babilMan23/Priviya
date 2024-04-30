#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>

#include "../maths/Maths.h"
#include "../renderer/elements/FBO.h"

namespace Priviya {

	struct URV {
		int width;
		int height;
		float mouseX;
		float mouseY;
	};

	inline extern void initializeCallbacks();

	//Methods
	inline extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	inline extern void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	inline extern bool isKeyDown(int Key);
	inline extern bool isKeyPressed(int Key);
	inline extern void updateCallbacks(GLFWwindow* window, URV* urv);

	static bool keys[GLFW_KEY_LAST + 8];
	static bool mouseButtons[GLFW_MOUSE_BUTTON_LAST + 8];
}
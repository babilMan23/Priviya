#include "WindowCallbacks.h"

void Priviya::initializeCallbacks() {
    memset(keys, false, sizeof(keys));
    memset(mouseButtons, false, sizeof(mouseButtons));
}

void Priviya::framebuffer_size_callback(GLFWwindow* window, int w, int h) {
	glViewport(0, 0, w, h);
    FBO* fbo = reinterpret_cast<FBO*>(glfwGetWindowUserPointer(window));
    fbo->ResizeFBO(w, h);
}

void Priviya::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	keys[key] = action;
}

bool Priviya::isKeyDown(int key) {
	return keys[key];
}

bool Priviya::isKeyPressed(int key) {
    for (int i = 0; i < 1024; i++) {
        if (keys[i] && i == key) {
            return true;
        }
    }
    return false;
}

void Priviya::updateCallbacks(GLFWwindow* window, URV* urv) {
    double mx, my;
    glfwGetCursorPos(window, &mx, &my);

    int scrw, scrh;

    glfwGetFramebufferSize(window, &scrw, &scrh);
    urv->width = scrw;
    urv->height = scrh;

    mx = Maths::clampd(mx, 0, scrw);
    my = Maths::clampd(my, 0, scrh);

    urv->mouseX = mx;
    urv->mouseY = my;
}
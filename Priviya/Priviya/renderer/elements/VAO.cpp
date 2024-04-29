#include "VAO.h"

void Priviya::VAO::linkVBO(vertex_buffer& vbo, int attr, int size) {
	vbo.bind();

	glVertexAttribPointer(attr, size, GL_FLOAT, false, 0, (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Priviya::VAO::create() {
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
}

void Priviya::VAO::bind() {
	glBindVertexArray(ID);
}

void Priviya::VAO::unbind() {
	glBindVertexArray(0);
}

void Priviya::VAO::destroy() {
	glDeleteVertexArrays(1, &ID);
}

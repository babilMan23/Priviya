#include "BufferObject.h"

void Priviya::vertex_buffer::create(std::vector<float> vertices) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(std::vector<float>), vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Priviya::vertex_buffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void Priviya::vertex_buffer::destroy() {
	glDeleteBuffers(1, &ID);
}

void Priviya::index_buffer::create(std::vector<uint> indices) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(std::vector<uint>), indices.data(), GL_STATIC_DRAW);
}

void Priviya::index_buffer::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void Priviya::index_buffer::destroy() {
	glDeleteBuffers(1, &ID);
}

#include "Model.h"

void Priviya::Model::create(std::vector<float> vertices, std::vector<uint> indices) {
	vao.create();

	vertexCount = indices.size();

	index_buffer ibo;
	ibo.create(indices);

	vertex_buffer vbo;
	vbo.create(vertices);
	vao.linkVBO(vbo, 0, 3);
}

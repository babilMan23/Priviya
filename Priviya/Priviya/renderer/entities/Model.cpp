#include "Model.h"

std::vector<float> vertices = {
	// Position (x, y)
	-0.5f,  0.5f,   // Top left
	0.5f,  0.5f,   // Top right
	0.5f, -0.5f,  // Bottom right
	-0.5f, -0.5f   // Bottom left
};

std::vector<uint> indices = {
	0, 1, 2,   // First triangle (top right, top left, bottom right)
	2, 3, 0    // Second triangle (bottom right, bottom left, top left)
};

std::vector<float> texCoords = {
	0, 0,
	1, 0,
	1, 1,
	0, 1
};

void Priviya::Model::create(std::string path) {
	vao.create();

	vertexCount = indices.size();

	index_buffer ibo;
	ibo.create(indices);

	vertex_buffer vbo;
	vbo.create(vertices);
	vao.linkVBO(vbo, 0, 2);

	vertex_buffer tbo;
	tbo.create(texCoords);
	vao.linkVBO(tbo, 1, 2);
}

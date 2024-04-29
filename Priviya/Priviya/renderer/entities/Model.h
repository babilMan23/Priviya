#pragma once

#include "../elements/VAO.h"

namespace Priviya {
	class Model {
	public:

		void create(std::vector<float> vertices, std::vector<uint> indices);

		VAO vao;
		uint vertexCount;
	};
}
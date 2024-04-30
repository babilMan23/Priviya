#pragma once

#include "../elements/VAO.h"

namespace Priviya {
	class Model {
	public:

		void create(std::string path);

		VAO vao;
		uint vertexCount;
	};
}
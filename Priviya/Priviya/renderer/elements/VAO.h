#pragma once

#include "BufferObject.h"

namespace Priviya {
	class VAO {
	public:

		VAO() = default;
		~VAO() = default;

		void linkVBO(vertex_buffer& vbo, int attr, int size);

		void create();
		void bind();
		void unbind();
		void destroy();
	private:
		uint ID;
	};
}
#pragma once

#include <glad/glad.h>
#include <vector>

#include "../../Core.h"

namespace Priviya {
	class BufferObject {
	public:

		BufferObject() = default;
		~BufferObject() = default;

		virtual void bind() = 0;
		virtual void destroy() = 0;

	protected:
		uint ID;
	};

	class vertex_buffer : public BufferObject {
	public:
		vertex_buffer() = default;
		~vertex_buffer() = default;

		void create(std::vector<float> vertices);
		void bind() override;
		void destroy() override;
	};

	class index_buffer : public BufferObject {
	public:
		index_buffer() = default;
		~index_buffer() = default;

		void create(std::vector<uint> indices);
		void bind() override;
		void destroy() override;
	};
}


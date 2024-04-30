#pragma once

#include <glad/glad.h>

#include "../Core.h"
#include "../util/Debug.h"

#include <iostream>
#include <string>
#include <fstream>

namespace Priviya {
	struct ShaderSource {
		string vss, fss;
	};
	
	class Shader {
	public:
		void use();
		void disable();
		void destroy();

		virtual void generate()=0;
	protected:
		void create(string name);
	private:
		string path = "res/shaders/";
		string extension = ".glsl";
		ShaderSource readFile(string path);
	private:
		uint vs, fs, program;
	};

	class DefaultShader : public Shader {
	public:
		DefaultShader() = default;
		~DefaultShader() = default;

		void generate() override;
	};
}

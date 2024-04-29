#include "Shader.h"

void Priviya::Shader::use() {
    glUseProgram(program);
}

void Priviya::Shader::disable() {
    glUseProgram(0);
}

void Priviya::Shader::destroy() {
    glDetachShader(program, vs);
    glDetachShader(program, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
    glDeleteProgram(program);
    PV_WARN("Deleted Shader");
}

void Priviya::Shader::create(string name) {
    PV_INFO("Creating Shader With Name : {}", name);

    ShaderSource source = readFile(path + name + extension);

    const char* vss = source.vss.c_str();
    const char* fss = source.fss.c_str();

    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vss, NULL);
    glCompileShader(vs);
    GLint vertex_compiled;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &vertex_compiled);
    if (vertex_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(vs, 1024, &log_length, message);
        PV_ERROR("Failed to initialie Vertex Shader : {}", message);
    }

    PV_INFO("Created Shader With Name : {}", name);
}

Priviya::ShaderSource Priviya::Shader::readFile(string path) {
    ShaderSource source = {};

    std::ifstream stream(path);

    if (!stream.is_open()) {
        PV_CRITICAL("Couldn't read file at path : " + path);
        std::cin.get();
        throw std::runtime_error("shader err");
    }

    string line;

    bool isVertex = false;

    string vss, fss;

    while (std::getline(stream, line)) {
        if (line.contains("//#VERTEX")) {
            isVertex = true;
        } else if (line.contains("//#FRAGMENT")) {
            isVertex = false;
        } else {
            if (isVertex) {
                vss.append(line).append("\n");
            } else {
                fss.append(line).append("\n");
            }
        }
    }

    stream.close();

    source.vss = vss;
    source.fss = fss;

    return source;
}

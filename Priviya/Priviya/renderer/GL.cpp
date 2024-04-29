#include "GL.h"

static PV_REF<Priviya::GL> opengl;

void Priviya::GL::prepare() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 0, 1);
}

void Priviya::GL::render(Model model) {
    model.vao.bind();
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model.vertexCount, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    model.vao.unbind();
}

bool Priviya::GL::create(bool debugContext) {

    PV_REF<Priviya::GL> glContext = std::make_shared<Priviya::GL>();
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        PV_CRITICAL("Failed to initialize GLAD!");
        std::cin.get();
        return false;
    }

    if (debugContext) {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(GLDebugMessageCallback, Priviya::GL::GLDebugMessageCallback);
        PV_INFO("Created Debug Context Succesfully");
    }

    char* version = (char*)glGetString(GL_VERSION);

    // Check if version string is not null
    if (version != nullptr) {
        char* ver = strtok_s(version, " ", &version); // strtok_s modifies the second parameter
        if (ver != nullptr) {
            PV_INFO("OpenGL Initialization info : ");
            PV_INFO("   Version:    {}", ver); // Using {} to format the version string
            // Additional info can be obtained by tokenizing further
            ver = strtok_s(nullptr, " ", &version); // Get next token (vendor)
            if (ver != nullptr) {
                PV_INFO("   Vendor :    {}", ver);
            }
            ver = strtok_s(nullptr, " ", &version); // Get next token (driver)
            if (ver != nullptr) {
                PV_INFO("   Driver :    {}", ver);
            }
        }
        else {
            PV_ERROR("Failed to parse OpenGL version string.");
        }
    }
    else {
        PV_ERROR("Failed to retrieve OpenGL version string.");
    }


    opengl = glContext;
    return true;
}

PV_REF<Priviya::GL> Priviya::GL::getGL() {
    return opengl;
}

void Priviya::GL::GLDebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* msg, const void* data) {
    const char* _source;
    const char* _type;
    const char* _severity;

    switch (source) {
    case GL_DEBUG_SOURCE_API:
        _source = "API";
        break;

    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        _source = "WINDOW SYSTEM";
        break;

    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        _source = "SHADER COMPILER";
        break;

    case GL_DEBUG_SOURCE_THIRD_PARTY:
        _source = "THIRD PARTY";
        break;

    case GL_DEBUG_SOURCE_APPLICATION:
        _source = "APPLICATION";
        break;

    case GL_DEBUG_SOURCE_OTHER:
        _source = "UNKNOWN";
        break;

    default:
        _source = "UNKNOWN";
        break;
    }

    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        _type = "ERROR";
        break;

    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        _type = "DEPRECATED BEHAVIOR";
        break;

    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        _type = "UDEFINED BEHAVIOR";
        break;

    case GL_DEBUG_TYPE_PORTABILITY:
        _type = "PORTABILITY";
        break;

    case GL_DEBUG_TYPE_PERFORMANCE:
        _type = "PERFORMANCE";
        break;

    case GL_DEBUG_TYPE_OTHER:
        _type = "OTHER";
        break;

    case GL_DEBUG_TYPE_MARKER:
        _type = "MARKER";
        break;

    default:
        _type = "UNKNOWN";
        break;
    }

    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        _severity = "HIGH";
        break;

    case GL_DEBUG_SEVERITY_MEDIUM:
        _severity = "MEDIUM";
        break;

    case GL_DEBUG_SEVERITY_LOW:
        _severity = "LOW";
        break;

    case GL_DEBUG_SEVERITY_NOTIFICATION:
        _severity = "NOTIFICATION";
        break;

    default:
        _severity = "UNKNOWN";
        break;
    }

    if (_severity == "NOTIFICATION") return;

    printf("%d: %s of %s severity, raised from %s: %s\n",
        id, _type, _severity, _source, msg);
}

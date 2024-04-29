//#VERTEX

#version 330 core

layout (location = 0) in vec3 aPos;

void main(void) {
	gl_Position = vec4(aPos, 1.0);
}

//#FRAGMENT

#version 330 core

out vec4 FragColor;

void main(void) {
	FragColor = vec4(1, 0, 0, 1);
}

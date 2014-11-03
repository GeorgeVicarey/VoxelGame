#version 150

in vec3 Color;
out vec4 outColour;

void main() {
	outColour = vec4(Color, 1.0);
}
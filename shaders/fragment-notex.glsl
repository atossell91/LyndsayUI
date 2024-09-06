#version 330 core

uniform vec3 Colour;

out vec4 FragColour;

void main() {
    FragColour = vec4(Colour.x, Colour.y, Colour.z, 1.0f);
}
#version 330 core

uniform vec4 Colour;

out vec4 FragColour;

void main() {
    FragColour = vec4(Colour.x, Colour.y, Colour.z, Colour.w);
}
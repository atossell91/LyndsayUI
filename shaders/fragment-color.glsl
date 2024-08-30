#version 330 core

in vec4 Colour;
in vec2 TexCoords;

out vec4 FragColour;

void main() {
    FragColour = Colour;
}
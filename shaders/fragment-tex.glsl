#version 330 core

in vec2 TexCoords;

out vec4 FragColour;

uniform sampler2D theTexture;

void main() {
    FragColour = texture(theTexture, TexCoords);
}
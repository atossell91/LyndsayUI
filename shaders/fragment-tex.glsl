#version 330 core

in vec2 TexCoords;

out vec4 FragColour;

uniform sampler2D theTexture;

void main() {
    FragColour = texture(theTexture, vec2(0.0f, 0.0f));
}
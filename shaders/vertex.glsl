#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColour;
layout(location = 2) in vec2 aTexCoords;

out vec4 Colour;
out vec2 TexCoords;

uniform float WidthScale;
uniform float HeightScale;

void main() {
    gl_Position = vec4(aPos.x / WidthScale, aPos.y / HeightScale, aPos.z, 1.0f);
    Colour = aColour;
    TexCoords = aTexCoords;
}

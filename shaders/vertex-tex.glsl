#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 2) in vec2 aTexCoords;

out vec4 Colour;
out vec2 TexCoords;

uniform mat4 Transform;

void main() {
    gl_Position = Transform * vec4(aPos.x, aPos.y, aPos.z, 1.0f);
    Colour = aColour;
    TexCoords = aTexCoords;
}

#pragma once

#include <string>

namespace BasicShaders {

// Populate the namespace here
    std::string TexVertex = "#version 330 core\nlayout(location=0)in vec3 aPos;layout(location=1)in vec2 aTexCoords;out vec2 TexCoords;uniform mat4 Transform;void main(){gl_Position=Transform*vec4(aPos.x, aPos.y, aPos.z, 1.0f);TexCoords=aTexCoords;}";
    std::string NoTexVertex = "#version 330 core\nlayout(location=0)in vec3 aPos;uniform mat4 Transform;void main(){gl_Position=Transform*vec4(aPos.x, aPos.y, aPos.z, 1.0f);}";
    std::string TexFragment = "#version 330 core\nin vec2 TexCoords;out vec4 FragColour;uniform sampler2D theTexture;void main(){FragColour=texture(theTexture, TexCoords);}";
    std::string NoTexFragment = "#version 330 core\nuniform vec4 Colour;out vec4 FragColour;void main(){FragColour=vec4(Colour.x, Colour.y, Colour.z, Colour.w);}";
} // BasicShaders

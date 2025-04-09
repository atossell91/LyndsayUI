#pragma once

#include <string>

namespace BasicShaders {

// Populate the namespace here
    std::string vertex = "#version 330 core\nlayout(location=0)in vec3 aPos;layout(location=1)in vec2 aTexCoords;out vec2 TexCoords;uniform mat4 Transform;void main(){gl_Position=Transform*vec4(aPos.x, aPos.y, aPos.z, 1.0f);TexCoords=aTexCoords;}";
    std::string fragment = "#version 330 core\nin vec2 TexCoords;out vec4 FragColour;uniform sampler2D theTexture;void main(){FragColour=texture(theTexture, TexCoords);}";
} // BasicShaders

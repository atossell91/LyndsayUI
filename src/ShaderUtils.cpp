#include "../include/ShaderUtilities.h"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "../include/glad/glad.h"

std::string NSLyndsayUI::ShaderUtils::ReadFile(const std::string& path) {
    std::ifstream fstream(path.c_str());
    std::stringstream strStream;
    strStream << fstream.rdbuf();
    return strStream.str();
}

int NSLyndsayUI::ShaderUtils::CompileShader(int ShaderType, const std::string& text) {
    int shader = glCreateShader(ShaderType);
    const char* cStr = text.c_str();
    glShaderSource(shader, 1, &cStr, NULL);
    glCompileShader(shader);
    
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    return shader;
}

void NSLyndsayUI::ShaderUtils::LinkProgram(int program) {
    glLinkProgram(program);
    
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(program, 512, NULL, infoLog);
        std::cout << "Link Info: " <<  infoLog << std::endl;   
    }
}

int NSLyndsayUI::ShaderUtils::BuildShaderProgram(const std::string& vShaderPath, const std::string& fShaderPath) {
    std::string vertShaderStr = ReadFile(vShaderPath);
    if (vertShaderStr.length() < 1) {
        std::cout << "Vertex shader is empty file." << std::endl;
    }

    std::string fragShaderStr = ReadFile(fShaderPath);
    if (fragShaderStr.length() < 1) {
        std::cout << "Fragment shader is empty file." << std::endl;
    }
    
    int vertShader = CompileShader(GL_VERTEX_SHADER, vertShaderStr);
    int fragShader = CompileShader(GL_FRAGMENT_SHADER, fragShaderStr);

    int prog = glCreateProgram();
    glAttachShader(prog, vertShader);
    glAttachShader(prog, fragShader);

    LinkProgram(prog);

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return prog;
}

#pragma once

#include <string>

namespace LyndsayUI
{
    namespace ShaderUtils
    {
        std::string ReadFile(const std::string& path);
        int CompileShader(int ShaderType, const std::string& text);
        void LinkProgram(int Program);
        int BuildShaderProgram(const std::string& vShaderPath, const std::string& fShaderPath);
    }
    
} // namespace LyndsayUI

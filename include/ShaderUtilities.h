#pragma once

#include <string>
#include <filesystem>

namespace NSLyndsayUI
{
    namespace ShaderUtils
    {
        std::string ReadFile(const std::string& path);
        std::string ReadFile(const char* path);
        int CompileShader(int ShaderType, const std::string& text);
        void LinkProgram(int Program);
        int BuildShaderProgram(const std::string& vShaderCode, const std::string& fShaderCode);
        int BuildShaderProgram(const std::filesystem::path& vShaderPath, const std::filesystem::path& fShaderPath);
    }
    
} // namespace NSLyndsayUI

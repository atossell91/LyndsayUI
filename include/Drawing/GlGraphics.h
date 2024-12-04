#pragma once

#include <string>
#include <vector>

#include <SDL3/SDL.h>

#include "glad/glad.h"
#include "IGraphics.h"
#include "BufferedImage.h"
#include "TransformParams.h"

namespace NSLyndsayUI {
    class GlGraphics : public IGraphics {
    private:
        //  Private stuff here
        SDL_Window* window;
        SDL_GLContext glContext;

        int solidShader = -1;
        int imgShader = -1;

        int quadVao = -1;

        int spiralVao = -1;
        int numSpiralData = 0;
        int spiralEbo;

        const char* TransformUniform = "Transform";

        static const int numQuadPoints = 20;
        const float quadVertices[numQuadPoints] {
            1.0f,   -1.0f,  0.0f,       1.0f, 0.0f, // Bottom Right
            1.0f,   1.0f,   0.0f,       1.0f, 1.0f,// Top Right
            -1.0f,  -1.0f,  0.0f,       0.0f, 0.0f,// Bottom Left
            -1.0f,  1.0f,   0.0f,       0.0f, 1.0f// Top Left
        };

        void initOpenGl();
        GLuint bufferPrimitive(const float vertices[], int size);

        void applyShaders(GLuint targetProgram);
        void applyTransforms(GLuint shaderProg, const TransformParams& params);
    public:
        //  Public stuff here
        GlGraphics(SDL_Window* window) : window{window}, glContext(SDL_GL_CreateContext(window)) {
            initOpenGl();
        }
        
        BufferedImage BufferImage(const std::string& imgPath);
        
        void DrawRectangle(const TransformParams& params);
        void DrawImage(BufferedImage image, 
            const Rectangle& sourceRect, const Rectangle& destRect, const TransformParams& params);
        void DrawString();
        void DrawLine(const TransformParams& params);

        std::vector<float> calcArcVertices(
            float startAngle, float arcAngle,
            float innerRadStart, float innerRadEnd,
            float outerRadStart, float outerRadEnd);
        void DrawSpiral(const TransformParams& params);
        void Clear();
    };
} // LyndsayUI

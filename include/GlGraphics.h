#pragma once

#include <string>
#include <vector>

#include <SDL3/SDL.h>

#include "glad/glad.h"
#include "IGraphics.h"

namespace RixinSDL {
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

        static const int numQuadPoints = 12;
        const float quadVertices[numQuadPoints] {
            1.0f, -1.0f, 0.0f, // Bottom Right
            1.0f, 1.0f, 0.0f, // Top Right
            -1.0f, -1.0f, 0.0f, // Bottom Left
            -1.0f, 1.0f, 0.0f, // Top Left
        };

        void initOpenGl();
        GLuint bufferPrimitive(const float vertices[], int size);
    public:
        //  Public stuff here
        GlGraphics(SDL_Window* window) : window{window}, glContext(SDL_GL_CreateContext(window)) {
            initOpenGl();
        }
        
        void DrawRectangle(const TransformParams& params);
        void DrawImage(const std::string& imgPath, 
            const Rectangle& sourceRect, const Rectangle& destRect);
        void DrawString();
        void DrawLine(const TransformParams& params);

        std::vector<float> calcArcVertices(
            float startAngle, float arcAngle,
            float innerRadStart, float innerRadEnd,
            float outerRadStart, float outerRadEnd);
        void DrawSpiral(const TransformParams& params);
        void Clear();
    };
} // RixinSDL

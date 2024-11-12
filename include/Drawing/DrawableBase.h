#pragma once

#include "glad/glad.h"

namespace LyndsayUI {
    class DrawableBase {
    protected:
        GLuint vao;
        GLuint shaderID;

        float zRotation = 0.0f;
        float xTranslate = 0.0f;
        float yTranslate = 0.0f;
        float xScale = 1.0f;
        float yScale = 1.0f;

        void initVertexArray() {
            glGenVertexArrays(1, &vao);
            glBindVertexArray(vao);
        }

    public:
        float getRotationZ() const { return zRotation; }
        float getTranslateX() const { return xTranslate; }
        float getTranslateY() const { return yTranslate; }
        float getScaleX() const { return xScale; }
        float getScaleY() const { return yScale; }

        void setRotationZ(float value) { zRotation = value; }
        void setTranslateX(float value) { xTranslate = value; }
        void setTranslateY(float value) { yTranslate = value; }
        void setScaleX(float value) { xScale = value; }
        void setScaleY(float value) { yScale = value; }

        DrawableBase(GLuint shaderProgramId) : shaderID{shaderProgramId} {
            initVertexArray();
        }

        DrawableBase(GLuint shaderProgramId, GLuint vao) : shaderID{shaderProgramId}, vao{vao} {}

        virtual void draw() = 0;
        virtual ~DrawableBase() {}
    };
}

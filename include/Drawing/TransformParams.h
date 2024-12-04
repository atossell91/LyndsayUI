#pragma once

namespace NSLyndsayUI {
    class TransformParams {
    private:
        //  Private stuff here
        float xRotation = 0.0f;
        float yRotation = 0.0f;
        float zRotation = 0.0f;
        float xScale = 1.0f;
        float yScale = 1.0f;
        float zScale = 1.0f;
        float xTranslation = 0.0f;
        float yTranslation = 0.0f;
        float zTranslation = 0.0f;
    public:
        //  Public stuff here
        float getXrotation() const { return xRotation; }
        void setXrotation(float val) { xRotation = val; }
        float getYrotation() const { return yRotation; }
        void setYrotation(float val) { yRotation = val; }
        float getZrotation() const { return zRotation; }
        void setZrotation(float val) { zRotation = val; }

        float getXscale() const { return xScale; }
        void setXscale(float val) { xScale = val; }
        float getYscale() const { return yScale; }
        void setYscale(float val) { yScale = val; }
        float getZscale() const { return zScale; }
        void setZscale(float val) { zScale = val; }

        float getXtranslation() const { return xTranslation; }
        void setXtranslation(float val) { xTranslation = val; }
        float getYtranslation() const { return yTranslation; }
        void setYtranslation(float val) { yTranslation = val; }
        float getZtranslation() const { return zTranslation; }
        void setZtranslation(float val) { zTranslation = val; }
    };
} // LyndsayUI

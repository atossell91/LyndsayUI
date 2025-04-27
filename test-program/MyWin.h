#pragma once

#include <glm/glm.hpp>

#include "Window/ImmediateWindow.h"
#include "Event/EventData/MouseButtonEventData.h"
#include "MyRect.h"
#include "KeyValues.h"
#include "Drawing/Colour.h"
#include "Point.h"
#include "PointPath.h"
#include "Drawing/PathDrawer.h"
#include "Constants.h"
#include "Curves.h"

namespace NSLyndsayUI {
    class MyWin : public ImmediateWindow {
    private:
        //  Private stuff here
        bool isSet = false;
        BufferedImage img;
        int tickCount = 0;
        float mouseX = 0;
        float mouseY = 0;



        bool wDown = false;
        bool aDown = false;
        bool sDown = false;
        bool dDown = false;

        MyRect rect;
        
        float trainX = 0.0f;
        float trainY = 0.0f;
        float trainT = 0.0f;
        float trainSpd = 0.0025f;

    public:
        //  Public stuff here
        void Setup() {
            //img = this->GetGraphics()->BufferImage("/home/ant/ghost.png");
            MouseButtonDown.AddEventHandler([this](auto d){MouseDownHandler(d);});
            MouseMoved.AddEventHandler([this](auto d){MouseMoveHandler(d);});
            KeyDown.AddEventHandler([this](auto d){KeyDownHandler(d);});
            KeyUp.AddEventHandler([this](auto d){KeyUpHandler(d);});
            //rect.setImg(img);
        }

        float mapCoord(float absCoord, float magnitude) {
            float half = magnitude/2;
            float pos = (absCoord-half)/half;
            return pos;
        }

        void KeyDownHandler(KeyboardEventData d) {

            KeyValues::KeyValue key = d.key;

            if (key == KeyValues::Keyboard_A && !aDown) {
                aDown = true;
                rect.hDir = -1;
            }

            if (key == KeyValues::Keyboard_D && !dDown) {
                dDown = true;
                rect.hDir = 1;
            }

            if (key == KeyValues::Keyboard_W && !wDown) {
                wDown = true;
                rect.vDir = 1;
            }

            if (key == KeyValues::Keyboard_S && !sDown) {
                sDown = true;
                rect.vDir = -1;
            }
        }

        void KeyUpHandler(KeyboardEventData d) {

            switch (d.key) {
            case KeyValues::Keyboard_A:
                aDown = false;
                rect.hDir = dDown ? 1 : 0;
                break;
            case KeyValues::Keyboard_D:
                dDown = false;
                rect.hDir = aDown ? -1 : 0;
                break;
            case KeyValues::Keyboard_W:
                wDown = false;
                rect.vDir = sDown ? -1 : 0;
                break;
            case KeyValues::Keyboard_S:
                sDown = false;
                rect.vDir = wDown ? 1 : 0;
                break;
            }
        }

        void MouseDownHandler(MouseButtonEventData d) {
        }

        void MouseMoveHandler(MouseMovedEventData d) {
            mouseX = mapCoord(d.MouseX, 1920);
            mouseY = -mapCoord(d.MouseY, 1080);
        }

        void Update() {
            rect.rot += 0.2;
            float speed = (rect.hDir && rect.vDir) ? rect.speed /1.4142 : rect.speed;
            rect.xPos += rect.hDir * speed;
            rect.yPos += rect.vDir * speed;

            
            Point p = Curves::evaluateCubic(
                Point(-0.6, -0.6),
                Point(0.9, -0.4),
                Point(-0.5, 1.5),
                Point(0.6, 0.6),
                trainT
            );

            trainT += trainSpd;
            trainX = p.X;
            trainY = p.Y;

            if (trainT >1.0f) trainT = 0.0f;
        }

        void DrawCircle(float rad, float xoff, float yoff, int samples) {

        }

        void Draw() {
            PointPath points;

            int samples = 100;
            float sampleSize = 360.0/samples *Constants::RadiansPerDegree;
            float rad = 0.5;
            for (int n =0; n <= samples; ++n) {
                float angle = sampleSize * n;
                float xpos = glm::cos(angle)*rad;
                float ypos = glm::sin(angle)*rad;
                Point p(xpos, ypos);
                points.AddPoint(p);
            }

            PointPath bezier;
            int bSamples = 50;
            float increment = 1.0 / bSamples;
            float t = 0.0;
            for (int n=0; n < bSamples; ++n) {
                Point p = Curves::evaluateCubic(
                    Point(-0.6, -0.6),
                    Point(0.9, -0.4),
                    Point(-0.5, 1.5),
                    Point(0.6, 0.6),
                    t
                );
                bezier.AddPoint(p);
                t += increment;
            }

            this->GetGraphics()->SetBackColour(Colours::GrassGreen);
            this->GetGraphics()->Clear();
            TransformParams imgParams, spiralParams;

            constexpr float num = 1920.0/1080.0;
            imgParams.setXscale(num);
            Rectangle rSource(0, 0, img.getWidth(), img.getHeight());
            Rectangle rDest(0, 0, 0, 0);

            //this->GetGraphics()->DrawImage(img, rSource, rDest, imgParams);

            spiralParams.setXtranslation(mouseX);
            spiralParams.setYtranslation(mouseY);
            spiralParams.setZrotation(tickCount);
            //this->GetGraphics()->DrawSpiral(spiralParams);

            TransformParams myParams;
            myParams.setXtranslation(mouseX);
            myParams.setYtranslation(mouseY);
            //this->GetGraphics()->DrawRectangle(myParams);
            //GetGraphics()->DrawImage(img, rSource, rDest, imgParams);
            //rect.draw(this->GetGraphics());

            //this->GetGraphics()->DrawPath(points, Colours::Red, 0.1f);
            this->GetGraphics()->DrawPath(bezier, Colours::DarkBrown, 0.03f);

            TransformParams trainParams;
            trainParams.setXtranslation(trainX/num);
            trainParams.setYtranslation(trainY);
            trainParams.setXscale(0.025f);
            trainParams.setYscale(0.025f);
            this->GetGraphics()->DrawRectangle(Colours::DarkGrey,trainParams);

            this->GetGraphics()->SwapBuffers();

            ++tickCount;
        }
    };
} // NSLyndsayUI

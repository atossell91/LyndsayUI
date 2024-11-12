#pragma once

namespace LyndsayUI {
    class ImageReference {
     private:
        int id;
        int width;
        int height;
     public:
        ImageReference(int i, int w, int h) : id{i}, width{w}, height{h} {}
        int GetId() const { return id; }
        int GetWidth() const { return width; }
        int GetHeight() const { return height; }
    };
}

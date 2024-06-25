#pragma once

class IUpdateable {
 public:
    virtual ~IUpdateable() {}
    virtual void Update() = 0;
};

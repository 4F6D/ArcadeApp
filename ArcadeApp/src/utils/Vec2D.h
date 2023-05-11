#pragma once
#include <iostream>

// 2D-Coordinate class
class Vec2D {
public:
    // Constructor
    Vec2D() : mX(0), mY(0) {}
    Vec2D(float x, float y) : mX(x), mY(y) {}
    
    // Set/Get
    inline void setX(float x) { mX = x; }
    inline void setY(float y) { mY = y; }
    inline float getX() { return mX; }
    inline float getY() { return mY; }

    // Overloaded equals operator
    bool operator==(const Vec2D& othervec2D)
    {
        return mX == othervec2D.mX && mY == othervec2D.mY;
    }

    friend std::ostream& operator<<(std::ostream & consoleOut, const Vec2D& vec);

    bool operator==(const Vec2D& vec2) const;
    bool operator!=(const Vec2D& vec2) const;
    
    
private:
    float mX,mY;
};

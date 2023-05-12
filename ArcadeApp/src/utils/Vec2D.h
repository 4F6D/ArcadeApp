#pragma once
#include <iostream>

// 2D-Coordinate class
class Vec2D {
public:
    
    
    // Constructor
    static const Vec2D Zero;                        // Zero vector
    Vec2D() : mX(0), mY(0) {}
    Vec2D(float x, float y) : mX(x), mY(y) {}
    
    // Set/Get
    inline void setX(float x) { mX = x; }
    inline void setY(float y) { mY = y; }
    inline float getX() { return mX; }
    inline float getY() { return mY; }

    friend std::ostream& operator<<(std::ostream & consoleOut, const Vec2D& vec);

    // Overloaded operators
    bool operator==(const Vec2D& vec2) const;       // Equal
    bool operator!=(const Vec2D& vec2) const;       // Not Equal
    Vec2D operator-() const;                        // Negation
    Vec2D operator*(float scale) const;             // Multiply with a scalar
    Vec2D operator/(float scale) const;             // Divide by a scalar
    Vec2D& operator*=(float scale);                 // Multiply and add
    Vec2D& operator/=(float scale);                 // Divide and add
    Vec2D operator+(const Vec2D& vec) const;        // Addition
    Vec2D operator-(const Vec2D& vec) const;        // Subtraction
    Vec2D& operator+=(const Vec2D& vec);            // Add
    Vec2D& operator-=(const Vec2D& vec);            // Subtract and add

    
    float magnitude() const;                        // Squareroot of Magnitude 
    float magnitude2() const;                       // Magnitude

    Vec2D getUnitVec() const;
    Vec2D& normalize();

    float distance(const Vec2D& vec) const;         // Distance
    float dot(const Vec2D& vec) const;              // Dot-Product

    Vec2D projectOnto(const Vec2D& vec) const;

    float angleBetween(const Vec2D& vec) const;
    Vec2D reflect(const Vec2D& normal) const;       // Reflect the Vector of this "normal"

    void rotate(float angle, const Vec2D& aroundPoint);
    Vec2D rotationResult(float angle, const Vec2D& aroundPoint) const;
    
    friend Vec2D operator*(float scale, const Vec2D& vec);

private:
    float mX,mY;
};

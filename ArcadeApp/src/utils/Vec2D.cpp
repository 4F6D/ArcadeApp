#include "Vec2D.h"
#include <assert.h>
#include "Utils.h"

// Overloaded console output for a Vector2D
std::ostream& operator<<(std::ostream & consoleOut, const Vec2D& vec)
{
    consoleOut << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
    return consoleOut;
}

// Overloaded operator if both vectors are EQUAL
bool Vec2D::operator==(const Vec2D& vec2) const
{
    return isEqual(mX, vec2.mX) && isEqual(mY, vec2.mY);
}

// Overloaded operator if both vectors are NOT EQUAL
bool Vec2D::operator!=(const Vec2D& vec2) const
{
    return (*this == vec2);
}

// Negating a vector
Vec2D Vec2D::operator-() const
{
    return Vec2D(-mX, -mY);
}

// Multiply Vec2D with a scalar
Vec2D Vec2D::operator*(float scale) const
{
    return Vec2D(scale * mX, scale * mY);
}

// reorder the sequence
Vec2D operator*(float scale, const Vec2D& vec)
{
    return vec * scale;
}

// Divide a Vec2D by a scalar
Vec2D Vec2D::operator/(float scale) const
{
    assert(fabsf(scale) > EPSILON);
    
    return Vec2D(mX / scale, mY / scale);
}

Vec2D& Vec2D::operator*=(float scale)
{
    *this = *this * scale;
    return *this;
}
Vec2D& Vec2D::operator/=(float scale)
{
    assert(fabsf(scale) > EPSILON);
    
    *this = *this / scale;
    return *this;
}
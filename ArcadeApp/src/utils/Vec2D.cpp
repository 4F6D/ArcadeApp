#include "Vec2D.h"
#include <assert.h>
#include "Utils.h"

const Vec2D Vec2D::Zero;

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

// Addition
Vec2D Vec2D::operator+(const Vec2D& vec) const
{
    return Vec2D(mX + vec.mX, mY + vec.mY);
}

// Subtraction
Vec2D Vec2D::operator-(const Vec2D& vec) const
{
    return Vec2D(mX - vec.mX, mY - vec.mY);
}

// Addition +=
Vec2D& Vec2D::operator+=(const Vec2D& vec)
{
    *this = *this + vec;
    return *this;
}

// Subtraction -=
Vec2D& Vec2D::operator-=(const Vec2D& vec)
{
    *this = *this - vec;
    return *this;
}

// Magnitude
float Vec2D::magnitude() const
{
    return sqrt(magnitude2());
}

float Vec2D::magnitude2() const
{
    return mX * mX + mY * mY;
}

// Normalize
Vec2D Vec2D::getUnitVec() const
{
    float mag = magnitude();

    if(mag > EPSILON) { return *this / mag; }
    else { return Vec2D::Zero; }
}

Vec2D& Vec2D::normalize()
{
    float mag = magnitude();

    if(mag > EPSILON) { *this /= mag; }

    return *this;
}

// Distance
float Vec2D::distance(const Vec2D& vec) const
{
    return (vec - *this).magnitude();
}

// Dot-product of two Vectors
float Vec2D::dot(const Vec2D& vec) const
{
    return (mX * vec.mX) + (mY * vec.mY);    
}

// Projection
Vec2D Vec2D::projectOnto(const Vec2D& vec) const
{
    Vec2D unitVec2 = vec.getUnitVec();

    float vecdot = dot(unitVec2);

    return unitVec2 * vecdot;
}

// Angle between vectors
float Vec2D::angleBetween(const Vec2D& vec) const
{
    return acosf(getUnitVec().dot(vec.getUnitVec()));
}

// Reflect the Vector of this "normal"
Vec2D Vec2D::reflect(const Vec2D& normal) const
{
    // v - 2(v dot n)n
    return *this - 2 * projectOnto(normal);
}

// Vector rotation
void Vec2D::rotate(float angle, const Vec2D& aroundPoint)
{
    float cosine = cosf(angle);
    float sine = sinf(angle);
    Vec2D thisVec(mX,mY);

    thisVec -= aroundPoint;

    float xRotation = thisVec.mX * cosine - thisVec.mY * sine;
    float yRoation = thisVec.mX * sine + thisVec.mY * cosine;

    Vec2D rot = Vec2D(xRotation,yRoation);
    
    *this = rot + aroundPoint;
}

Vec2D Vec2D::rotationResult(float angle, const Vec2D& aroundPoint) const
{
    float cosine = cosf(angle);
    float sine = sinf(angle);
    Vec2D thisVec(mX,mY);

    thisVec -= aroundPoint;

    float xRotation = thisVec.mX * cosine - thisVec.mY * sine;
    float yRoation = thisVec.mX * sine + thisVec.mY * cosine;

    Vec2D rot = Vec2D(xRotation,yRoation);

    return rot + aroundPoint;
}
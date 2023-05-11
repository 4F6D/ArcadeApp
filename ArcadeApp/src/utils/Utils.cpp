#include "Utils.h"
#include <cmath>

// Tolerance value for float comparison
static const float EPSILON = 0.0001f;

// Definition of the comparison if two floats are equal(with tolerance)
bool isEqual(float x, float y)
{
    return fabsf(x - y) < EPSILON;
}

bool isGreaterThanOrEqual(float x, float y)
{
    return x > y || isEqual(x,y);
}

bool isLessThanOrEqual(float x, float y)
{
    return x < y || isEqual(x,y);
}
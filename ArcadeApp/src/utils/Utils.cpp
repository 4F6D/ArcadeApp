#include "Utils.h"
#include <cmath>

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
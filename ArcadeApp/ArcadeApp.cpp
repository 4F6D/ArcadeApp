#include <iostream>

// 2D-Coordinate class
class Point2D {
public:
    Point2D(int x, int y);
    Point2D();

    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    void display();

private:
    int mX;
    int mY;
};

// Constructors
Point2D::Point2D()
{
    mX = 0;
    mY = 0;
}

Point2D::Point2D(int x, int y)
{
    mX = x;
    mY = y;
}

// Setter
void Point2D::setX(int x)
{
    mX = x;
}

void Point2D::setY(int y)
{
    mY = y;
}

// Getter
int Point2D::getX()
{
    return mX;
}

int Point2D::getY()
{
    return mY;
}

// Display
void Point2D::display()
{
    std::cout << "X: " << mX << ", Y: " << mY;
}

int main(int argc, char* argv[]){
    // Base stuff
}

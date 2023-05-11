//===================================================================================
// Name         : ArcadeApp.cpp
// Author       : René R.
// Version      :
// Copyright    : None
// Description  : Arcade App to play different old school Arcade games made in C++
//                for learning purposes
//===================================================================================

#include <iostream>

// 2D-Coordinate class
class Point2D {
public:
    // Constructor
    Point2D() : mX(0), mY(0) {}

    Point2D(int x, int y) : mX(x), mY(y) {}

    // Deconstructor 
    ~Point2D()
    {
        std::cout << "Point2D deconstructor called!";
    }
    

    // Set/Get
    void setX(int x) { mX = x; }
    void setY(int y) { mY = y; }
    int getX() { return mX; }
    int getY() { return mY; }

    void display();
    
private:
    int mX;
    int mY;
};

// Display
void Point2D::display()
{
    std::cout << "X: " << mX << ", Y: " << mY;
}

int main(int argc, char* argv[]){
    // Base stuff

}

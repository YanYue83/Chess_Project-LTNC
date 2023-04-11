#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>

class Vector2D{
    public:
        float X, Y;

    public:
        Vector2D(float x=0, float y=0): X(x), Y(y) {}

    public:
        // addition +
        inline Vector2D operator+(const Vector2D& v2) const {
            return Vector2D(X + v2.X, Y + v2.Y);
        }

        // difference -
        inline Vector2D operator-(const Vector2D& v2) const {
            return Vector2D(X - v2.X, Y - v2.Y);
        }

        // multiplication *
        inline Vector2D operator*(const float n) const {
            return Vector2D(X*n, Y*n);
        }

        void Log(std::string msg = ""){
            std::cout << msg << "(X Y) = (" << X << " " << Y << ")"<< std::endl;
        }
};

#endif // VECTOR_2D_H
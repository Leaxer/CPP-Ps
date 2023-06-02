#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
    private:
        int x;
        int y;
    public:
        Vector2D();
        Vector2D(int userInputX, int userInputY);
        void SetX(int userInput);
        void SetY(int userInput);
        int GetX() const;
        int GetY() const;
        int operator *(const Vector2D& B);
};

Vector2D::Vector2D() {
    x = 0;
    y = 0;
}

Vector2D::Vector2D(int userInputX, int userInputY) {
    x = userInputX;
    y = userInputY;
}

void Vector2D::SetX(int userInput) {
    x = userInput;
}

void Vector2D::SetY(int userInput) {
    y = userInput;
}

int Vector2D::GetX() const{
    return x;
}

int Vector2D::GetY() const{
    return y;
}

int Vector2D::operator *(const Vector2D& B) {
    return (x * B.GetX()) + (y * B.GetY());
}

int main() {
    Vector2D v1(5,8), v2(2,4), v3(8,9), v4(6,10);
    cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX() << "," << v2.GetY() << ") = " << v1*v2 << endl;
    cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX() << "," << v3.GetY() << ") = " << v2*v3 << endl;
    cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX() << "," << v4.GetY() << ") = " << v3*v4 << endl;
}
#include <iostream>
#include <vector>

using namespace std;

class MyInteger {
    private:
        int number;
    public:
        MyInteger();
        MyInteger(int num);
        void SetNumber(int a);
        int GetNumber();
        int operator [](const int& index);
};

MyInteger::MyInteger() {
    number = -1;
}

MyInteger::MyInteger(int num) {
    number = num;
}

void MyInteger::SetNumber(int num) {
    number = num;
}

int MyInteger::GetNumber() {
    return number;
}

int MyInteger::operator [](const int& index) {
    if(index < 0) return -1;
    int i = 0,temp;
    temp = number;
    while(i != index) {
        temp /= 10;
        ++i;
    }
    if(temp == 0 && index != 0) return -1;
    int remainder = temp%10;
    return remainder;
}
int main() {
    MyInteger num(7128);
    cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << endl;
    cout << num[4] << endl;
    cout << num[-1] << endl;
}
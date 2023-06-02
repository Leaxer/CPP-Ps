#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {
    private:
        double *coeffPtr;
        int size;
    public:
        Polynomial();
        Polynomial(const Polynomial& secondObject);
        Polynomial(double *arr, int num);
        Polynomial operator =(const Polynomial& secondObject);
        ~Polynomial();
        friend Polynomial operator +(const Polynomial& p1, const Polynomial& p2);
        friend Polynomial operator -(const Polynomial& p1, const Polynomial& p2);
        friend Polynomial operator *(const Polynomial& p1, const Polynomial& p2);
        int mySize() {return size;}
        double& operator[](int degree);
        const double& operator[](int degree) const;
};

Polynomial::Polynomial() {
    coeffPtr = new double;
    *coeffPtr = 0;
    size = 0;
}

Polynomial::Polynomial(const Polynomial& secondObject) {
    size = secondObject.size;
    coeffPtr = new double[size];
    for (int i = 0; i < size; i++) {
        coeffPtr[i] = secondObject.coeffPtr[i];
    }
}

Polynomial::Polynomial(double *arr, int num) {
    size = num;
    coeffPtr = new double[size];
    for (int i = 0; i < size; i++) {
        coeffPtr[i] = arr[i];
    }
}

Polynomial Polynomial::operator =(const Polynomial& secondObject) {
    if(secondObject.coeffPtr == coeffPtr) {
        return secondObject;
    }
    size = secondObject.size;
    delete[] coeffPtr;
    coeffPtr = new double[size];
    for (int i = 0; i < size; i++) {
        coeffPtr[i] = secondObject.coeffPtr[i];
    }
    Polynomial result(*this);
    return result;
}

Polynomial::~Polynomial() {
    delete[] coeffPtr;
}

 
Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
    int degree;
    if(p1.size > p2.size) degree = p1.size;
    else degree = p2.size;
    Polynomial lastObject;
    lastObject.size = degree;
    lastObject.coeffPtr = new double[degree];
    for (int i = 0; i < degree; i++) {
        lastObject.coeffPtr[i] = p1[i] + p2[i];
    }
    return lastObject;
}

Polynomial operator-(const Polynomial& p1, const Polynomial& p2) {
    int degree;
    if(p1.size > p2.size) degree = p1.size;
    else degree = p2.size;
    Polynomial lastObject;
    lastObject.size = degree;
    lastObject.coeffPtr = new double[degree];
    for (int i = 0; i < degree; i++) {
        lastObject.coeffPtr[i] = p1[i] - p2[i];
    }
    return lastObject;
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
    int i,j;
    int prodSize = p1.size + p2.size - 1;
    double *prodCoefs = new double[prodSize];
    for(i = 0;i < prodSize;i++)
        prodCoefs[i] = 0;
    for(i = 0;i < p1.size;i++) {
        for(j = 0;j < p2.size;j++) {
            prodCoefs[i+j] += p1[i] * p2[j];
        }
    }
    return Polynomial(prodCoefs, prodSize);
}

double& Polynomial::operator[](int degree) {
    return coeffPtr[degree];
}

const double& Polynomial::operator[](int degree) const {
    return coeffPtr[degree];
}

double evaluate(Polynomial& p, double x) {
    double result = 0;
    for (int i = 0; i < p.mySize(); i++) {
        result += p[i] * pow(x, i);
    }
    return result;
}

int main()
{
    Polynomial empty;
    double one[] = {1};
    Polynomial One(one, 1);
    double quad[] = {3, 2, 1};
    double cubic[] = {1, 2, 0, 3};
    Polynomial q(quad, 3); // q is 3 + 2*x + x*x
    Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
    Polynomial p = q; // test copy constructor
    Polynomial r;
    r = q; //test operator=
    r = c;
    cout << "Polynomial q " << endl;
    {for(int i = 0; i < 3; i++)
    cout << "term with degree " << i
    << " has coefficient " << q[i] << endl;
    }
    cout << "Polynomial c " << endl;
    {for(int i = 0; i < 4; i++)
    cout << "term with degree " << i
    << " has coefficient " << c[i] << endl;
    }
    cout << "value of q(2) is " << evaluate(q, 2) << endl;
    cout << "value of p(2) is " << evaluate(p, 2) << endl;
    cout << "value of r(2) is " << evaluate(r, 2) << endl;
    cout << "value of c(2) is " << evaluate(c, 2) << endl;
    r = q + c;
    cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;
    r = q - c;
    cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;
    r = q * c;
    cout << "size of q*c is " << r.mySize() << endl;
    cout << "Polynomial r (= q*c) " << endl;
    for(int i = 0; i < r.mySize(); i++)
    cout << "term with degree " << i
    << " has coefficient " << r[i] << endl;
    cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
    return 0;
}
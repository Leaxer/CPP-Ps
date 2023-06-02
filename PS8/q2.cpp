#include <iostream>

using namespace std;

template<typename T1, typename T2>
class Pair {
    public:
        Pair(T1 first, T2 second);
        T1 getFirst() const;
        T2 getSecond() const;
        void setFirst(T1 first);
        void setSecond(T2 second);
    private:
        T1 first;
        T2 second;
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(T1 first, T2 second) {
    this->first = first;
    this->second = second;
}

template<typename T1, typename T2>
T1 Pair<T1, T2>::getFirst() const { 
    return first; 
}

template<typename T1, typename T2>
T2 Pair<T1, T2>::getSecond() const { 
    return second; 
}

template<typename T1, typename T2>
void Pair<T1, T2>::setFirst(T1 first) { 
    this->first = first; 
}

template<typename T1, typename T2>
void Pair<T1, T2>::setSecond(T2 second) { 
    this->second = second; 
}

int main() {
    Pair<char, char> p('A', 'B');
    cout << "First is " << p.getFirst() << endl;
    p.setFirst('Z');
    cout << "First changed to " << p.getFirst() << endl;
    cout << "The pair is: " << p.getFirst() << ", " << p.getSecond() << endl;

    Pair<int, string> p2(34, "Bill");
    Pair<string, int> p3("Bill", 34);
    cout << "The pair is: " << p2.getFirst() << ", " << p2.getSecond() << endl;

    return 0;
}

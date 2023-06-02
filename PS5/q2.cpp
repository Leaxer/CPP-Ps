#include <iostream>

using namespace std;

class Student {
    private:
        string name;
        int numClasses;
        string *classList;
    public:
        Student();
        Student& operator =(const Student& s2);
        ~Student();
        void OutputData();
        void InputData();
        void ResetClasses();
};

Student::Student() {
    name = "";
    numClasses = 0;
    classList = nullptr;
}

Student& Student::operator =(const Student& s2) {
    if(s2.classList == this->classList) {
        return *this;
    }
    name = s2.name;
    numClasses = s2.numClasses;
    delete[] classList;
    classList = new string[numClasses];
    for (int i = 0; i < numClasses; i++) {
        classList[i] = s2.classList[i];
    }
    return *this;
}

Student::~Student() {
    delete[] classList;
}

void Student::InputData() {
    ResetClasses();
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter number of classes: ";
    cin >> numClasses;
    cin.ignore(2,'\n');
    if(numClasses > 0) {
        classList = new string[numClasses];
        for(int i = 0;i < numClasses;i++) {
            cout << "Enter name of the class " << (i+1) << endl;
            getline(cin, classList[i]);
        }
    }
    cout << endl;
}

void Student::OutputData() {
    cout << "Student name: " << name << endl;
    cout << "Number of classes: " << numClasses <<endl;
    cout << "The names of the classes that the student is enrolled in:" << endl;
    for(int i = 0;i < numClasses;i++) {
        cout << classList[i] << endl;
    }
    cout << endl;
}

void Student::ResetClasses() {
    numClasses = 0;
    delete[] classList;
    classList = nullptr;
}

int main()
{
    Student s1, s2;
    s1.InputData(); // Input data for student 1
    cout << "Student 1's data:" << endl;
    s1.OutputData(); // Output data for student 1
    cout << endl;
    s2 = s1;
    cout << "Student 2's data after assignment from student 1:" << endl;
    s2.OutputData(); // Should output same data as for student 1
    s1.ResetClasses();
    cout << "Student 1's data after reset:" << endl;
    s1.OutputData(); // Should have no classes
    cout << "Student 2's data, should still have original classes:" << endl;
    s2.OutputData(); // Should still have original classes
    cout << endl;
    return 0;
}
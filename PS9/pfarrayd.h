// This is the HEADER FILE pfarrayd.h. This is the INTERFACE for the
// class PFArrayD. Objects of this type are partially filled arrays
// of doubles.

// The class PFArrayD has been modified by moving the member
// function definitions that are longer than one line to the
// implementation file, PFArrayD.cpp.

// The definition of a class OutOfRange has been added. The <string>
// header, needed for OutOfRange and its member functions, has been
// included.

#ifndef PFARRAYD_H
#define PFARRAYD_H

#include <string>
using std::string;

class Exception
{
};

class OutOfRange : public Exception
{
    public:
        OutOfRange(string thisMessage, int thisIndex);
        string getMessage() const;
        int getIndex() const;
    private:
        string message;
        int index;
};

// Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
    public:
    PFArrayD();
    // Initializes with a capacity of 50.
    PFArrayD(int capacityValue);
    PFArrayD(const PFArrayD& pfArrayObject);
    void addElement(double element);
    // Precondition: The array is not full.
    // Postcondition: The element has been added.
    bool full() const { return (capacity == used); }
    // Returns true if the array is full, false otherwise.
    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    void emptyArray() { used = 0; }
    // Empties the array.
    double& operator[](int index);
    // Read and change access to elements 0 through numberUsed - 1.
    PFArrayD& operator=(const PFArrayD& rightSide);
    ~PFArrayD();

    private:
    double* a; // for an array of doubles.
    int capacity; // for the size of the array.
    int used; // for the number of array positions currently in use.
};

#endif // PFARRAYD_H
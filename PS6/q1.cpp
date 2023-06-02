#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class DynamicStringArray {
    private:
        string *dynamicArray;
        int size;
    public:
        DynamicStringArray() {
            dynamicArray = NULL;
            size = 0;
        }
        DynamicStringArray(const DynamicStringArray &other)
        {
            size = other.size;
            if(size == 0) {
                dynamicArray = NULL;
            }else {
                dynamicArray = new string[size];
                for (int i = 0; i < size; i++)
                {
                    dynamicArray[i] = other.dynamicArray[i];
                }
            }
        }
        void setSize(int s) {size = s;}
        int getSize() const{return size;}
        void addEntry(string userInput) {
            string *tempArr;
            tempArr = new string[size+1];
            for(int i = 0;i < size;i++) {
                *(tempArr+i) = *(dynamicArray+i);
            }
            *(tempArr+size) = userInput;
            size++;
            delete[] dynamicArray;
            dynamicArray = tempArr;
        }
        bool deleteEntry(string userInput) {
            if(size <= 0) {return false;}
            int check = -1,a = 0;
            for(int i = 0;i < size;i++) {
                if(*(dynamicArray+i) == userInput) {
                    check = i;
                }
            }
            if(check == -1) {return false;}
            string *tempArr;
            tempArr = new string[size-1];
            for(int i = 0;i < size;i++) {
                if(i != check) {
                    *(tempArr+a) = *(dynamicArray+i);
                    a++;
                }
            }
            size--;
            delete[] dynamicArray;
            dynamicArray = tempArr;
            return true;
        }
        string getEntry(int index) const {
            if(index >= size || index < 0) {return NULL;}
            return dynamicArray[index];
        }
        DynamicStringArray& operator=(const DynamicStringArray &other)
        {
            if(dynamicArray != NULL) {
                delete[] dynamicArray;
            }
            if(other.size == 0) {
                size = 0;
                dynamicArray = NULL;
            }else {
                size = other.size;
                dynamicArray = new string[size];
                for (int i = 0; i < size; i++)
                {
                    dynamicArray[i] = other.dynamicArray[i];
                }
            }
            return *this;
        }
        ~DynamicStringArray() {
            if(dynamicArray != NULL) {
                delete[] dynamicArray;
            }
        }
};
int main()
{
    DynamicStringArray names;
    // List of names
    names.addEntry("Frank");
    names.addEntry("Wiggum");
    names.addEntry("Nahasapeemapetilon");
    names.addEntry("Quimby");
    names.addEntry("Flanders");
    // Output list
    cout << "List of names:" << endl;
    for (int i = 0; i < names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;
    // Add and remove some names
    names.addEntry("Spuckler");
    cout << "After adding a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Nahasapeemapetilon");
    cout << "After removing a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Skinner");
    cout << "After removing a name that isn't on the list:" << endl;
    for (int i = 0; i < names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;
    names.addEntry("Muntz");
    cout << "After adding another name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;
    // Remove all of the names by repeatedly deleting the last one
    while (names.getSize() > 0) {
    names.deleteEntry(names.getEntry(names.getSize() - 1));
    }
    cout << "After removing all of the names:" << endl;
    for (int i = 0; i < names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;
    names.addEntry("Burns");
    cout << "After adding a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;
    cout << "Testing copy constructor" << endl;
    DynamicStringArray names2(names);
    // Remove Burns from names
    names.deleteEntry("Burns");
    cout << "Copied names:" << endl;
    for (int i = 0; i < names2.getSize(); i++)
    cout << names2.getEntry(i) << endl;
    cout << endl;
    cout << "Testing assignment" << endl;
    DynamicStringArray names3 = names2;
    // Remove Burns from names2
    names2.deleteEntry("Burns");
    cout << "Copied names:" << endl;
    for (int i = 0; i < names3.getSize(); i++)
    cout << names3.getEntry(i) << endl;
    cout << endl;
    cout << "Enter a character to exit." << endl;
    char wait;
    cin >> wait;
    return 0;
}
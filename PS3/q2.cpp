#include <iostream>
#include <vector>

using namespace std;

class Suitor {
    public:
        Suitor();
        // Set id with constructor
        Suitor(int newId);
        // Return id
        int GetId();
        void SetId(int newId);
    private:
        int id;
};

// Suitor class contructors and methods
Suitor::Suitor() {
    id = 0;
}
// Set id with constructor
Suitor::Suitor(int newId) : id(newId){
}
// Return id
int Suitor::GetId() {
    return id;
}
// Set id
void Suitor::SetId(int newId) {
    id = newId;
}

int main() {
    int n;
    vector<Suitor> suitors;
    cout << "Enter the number of suitors: ";
    cin >> n;
    // Initialize new suitor and add object to vector
    for(int i = 0;i < n;++i) {
        suitors.push_back(Suitor(i+1));
    }
    for(int i = 0;i < n;++i) {
        cout << suitors[i].GetId();
    }
    cout << " initial list of suitors, start counting from 1" << endl;
    int index = 0;
    // Loop until one person left
    while (suitors.size() > 1) {
        index = (index + 2) % suitors.size();
        // Which element will be erase
        for(int i = 0;i < suitors.size();++i) {
            if(i == index) {

            }else {
                cout << suitors[i].GetId();
            }
        }
        cout << " suitor " << suitors[index].GetId() << " eliminated, ";
        if(suitors.size() != 2) {
            cout << "continue counting from ";
            if(index+1 == suitors.size()) {
                cout << suitors[0].GetId() << endl;
            }else {
                cout << suitors[index+1].GetId() << endl;
            }
        }
        suitors.erase(suitors.begin() + index);
    }
    cout << suitors[0].GetId() << " is the lucky winner" << endl;
}
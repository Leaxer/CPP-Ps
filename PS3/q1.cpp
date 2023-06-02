#include <iostream>

using namespace std;


class HotDogStand {
    public:
        HotDogStand();
        HotDogStand(int newId, int newSoldProducts);
        // Call if stand sold one hot dog
        // Increase one time soldProducts and totalSold
        void JustSold();
        // Return soldProducts
        int getSoldProducts();
        // Return id
        int getId();
        // Set id with method
        void SetId(int newId);
        // Return total amount of hot dogs sold
        static int GetTotalSold();
    private:
        static int totalSold;
        int id;
        int soldProducts;
};

int HotDogStand::totalSold = 0;

// HotDogStand class contructors and methods
HotDogStand::HotDogStand() {
    id = 0;
    soldProducts = 0;
}
HotDogStand::HotDogStand(int newId, int newSoldProducts) : id(newId) , soldProducts(newSoldProducts) {
    totalSold += soldProducts;
}
// Call if stand sold one hot dog
// Increase one time soldProducts and totalSold
void HotDogStand::JustSold() {
    cout << "HotDog Stand-" << id << " sold one product" << endl;
    ++soldProducts;
    ++totalSold;
}
// Return soldProducts
int HotDogStand::getSoldProducts() {
    return soldProducts;
}
// Return id
int HotDogStand::getId() {
    return id;
}
// Set id with method
void HotDogStand::SetId(int newId) {
    id = newId;
}
// Return total amount of hot dogs sold
int HotDogStand::GetTotalSold() {
    return totalSold;
}

int main() {
    // Initialize objects
    HotDogStand h1(1,1);
    HotDogStand h2(2,4);
    HotDogStand h3(3,5);
    // Show their amounts at beginning
    cout << "Current amout of hot dogs sold on h1: " << h1.getSoldProducts() << endl;
    cout << "Current amout of hot dogs sold on h2: " << h2.getSoldProducts() << endl;
    cout << "Current amout of hot dogs sold on h3: " << h3.getSoldProducts() << endl;
    cout << "Total amount of hot dogs sold: " << HotDogStand::GetTotalSold() << endl;
    h1.JustSold();
    h1.JustSold();
    h1.JustSold();
    cout << "Total on hot dog stand-" << h1.getId() << ": " << h1.getSoldProducts() << endl;
    h2.JustSold();
    h2.JustSold();
    cout << "Total on hot dog stand-" << h2.getId() << ": " << h2.getSoldProducts() << endl;
    h3.JustSold();
    h3.JustSold();
    cout << "Total on hot dog stand-" << h3.getId() << ": " << h3.getSoldProducts() << endl;
    cout << "Total amount of hot dogs sold: " << h1.GetTotalSold() << endl;
}